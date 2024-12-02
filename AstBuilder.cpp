#include "AstBuilder.h"

AstBuilder::AstBuilder(BufferedTokenStream& t): bufferedTokens(t), astTree(std::make_shared<ProgramNode>()) {}


bool AstBuilder::isConditionBlockOK(HadesParser::ConditionBlockContext *ctx)
{
	return ctx && ctx->LEFTBRACKET() && ctx->RIGHTBRACKET();
}

bool AstBuilder::isCodeBlockOK(HadesParser::CodeBlockContext *ctx)
{
	return ctx && ctx->LEFTCURLYBRACKET() && ctx->RIGHTCURLYBRACKET();
}

void AstBuilder::printAst()
{
	astTree->print(0);
}

std::shared_ptr<ProgramNode> AstBuilder::getAstTree()
{
	return astTree;
}

std::any AstBuilder::visitProgram(HadesParser::ProgramContext *ctx)
{
	if(!astTree)
		return std::any(0);

	path.push(astTree);

	for(const auto &child: ctx->children)
		visit(child);
	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitFunctionDefinition(HadesParser::FunctionDefinitionContext *ctx)
{
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.top());
	std::shared_ptr<FunctionDefNode> func = std::make_shared<FunctionDefNode>();
	if(!func)
		return std::any(0);

	top->codeNodes.push_back(func);
	func->name = ctx->ALPHANUMERIC()->getText();
	path.push(func->body);
	visit(ctx->codeBlock());
	path.pop();

	return std::any(1);
}

std::any AstBuilder::visitIfStatement(HadesParser::IfStatementContext *ctx)
{
	auto elseIfs = ctx->elseIfStatement();
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.top());
	std::shared_ptr<IfStatementNode> topIf = std::make_shared<IfStatementNode>((1+elseIfs.size())*2);
	if(!topIf || !topIf->noNull())
		return std::any(0);
	if(!isConditionBlockOK(ctx->conditionBlock()) || !isCodeBlockOK(ctx->codeBlock()))
		throw std::runtime_error("BAD IF");

	top->codeNodes.push_back(topIf);

	path.push(topIf->condCodeNodes[0]);
	visit(ctx->conditionBlock());
	path.pop();
	path.push(topIf->condCodeNodes[1]);
	visit(ctx->codeBlock());
	path.pop();

	int j=2;
	for(int i=0; i<elseIfs.size(); i++)
	{
		path.push(topIf->condCodeNodes[j]);
		visit(elseIfs[i]->conditionBlock());
		path.pop();
		path.push(topIf->condCodeNodes[j+1]);
		visit(elseIfs[i]->codeBlock());
		path.pop();
		j+=2;
	}

	if(ctx->elseStatement())
	{
		path.push(topIf);
		visit(ctx->elseStatement());
		path.pop();
	}
	return std::any(1);
}

std::any AstBuilder::visitElseStatement(HadesParser::ElseStatementContext *ctx)
{
	std::shared_ptr<IfStatementNode> ifNode = dynamic_pointer_cast<IfStatementNode>(path.top());
	if(!ifNode->elseNode)
		return std::any(0);

	path.push(ifNode->elseNode);
	visit(ctx->codeBlock());

	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitWhileLoop(HadesParser::WhileLoopContext *ctx)
{
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.top());
	std::shared_ptr<WhileLoopNode> loop = std::make_shared<WhileLoopNode>();
	if(!loop)
		return std::any(0);

	top->codeNodes.push_back(loop);
	
	path.push(loop->condition);
	visit(ctx->conditionBlock());
	path.pop();

	path.push(loop->body);
	visit(ctx->codeBlock());
	path.pop();
	return std::any(1);
}

void AstBuilder::runAsssignmentParser(std::string sentence)
{
	ANTLRInputStream input(sentence);
	AssignmentLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	AssHadesParser parser(&tokens);
	std::shared_ptr<AssignmentErrorStrategy> handler = std::make_shared<AssignmentErrorStrategy>();
	if(!handler) // maybe throw here
		return;
	parser.setErrorHandler(handler);
	ParseTree *tree = parser.assignments();
	AssignmentProcessor assProc(path);
	assProc.visit(tree);
}

std::string AstBuilder::recoverSpacesFromTokens(HadesParser::WordsContext *ctx)
{
	std::string ret;
    size_t start = ctx->getStart()->getTokenIndex();
    size_t stop = ctx->getStop()->getTokenIndex();
	std::vector<Token*> tokList = bufferedTokens.getTokens(start, stop);
	for(auto t=tokList.begin(); t!=tokList.end(); t++)
	{
		std::string processingWord = (*t)->getText();
		if((*t)->getType() == HadesParser::UNCLOSED_QUOTED_STRING)
			throw std::runtime_error("UNCLOSED");

		if(t == (tokList.end()-1))
		{
			size_t c = 0;
			for(c=processingWord.size()-1; c>=0 && processingWord[c] == '\\';)
				c--;
			
			if((processingWord.size()-1-c)%2)
				throw std::runtime_error("UNSLASHED");
		}
		ret += processingWord;
	}
	return ret;
}

void AstBuilder::pseudoVisitWords(HadesParser::WordsContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = std::dynamic_pointer_cast<SentenceNode>(path.top());
	std::string sentenceWithSpaces = recoverSpacesFromTokens(ctx);
	try
	{
		runAsssignmentParser(sentenceWithSpaces);
	}
	catch(size_t pos)
	{

		topSentence->content.clear();
		ANTLRInputStream input = ANTLRInputStream(sentenceWithSpaces.substr(pos));
		SentenceHadesLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		SentenceHadesParser parser(&tokens);
		
		ParseTree *tree = parser.sentence();
		SentenceProcessor sentenceProc(path);
		sentenceProc.visit(tree);
	}
}

std::shared_ptr<SentenceNode> AstBuilder::pushToProgramOrSentence(bool stricte)
{
	std::shared_ptr<AstNode> baseTop = path.top();
	std::shared_ptr<ProgramNode> topProgram;
	std::shared_ptr<SentenceNode> topSentence = nullptr;
	std::shared_ptr<SentenceNode> sentence = std::make_shared<SentenceNode>();
	if(!sentence)
		return nullptr;

	if(topProgram = std::dynamic_pointer_cast<ProgramNode>(baseTop))
	{
		topProgram->codeNodes.push_back(sentence);
		path.push(topProgram->codeNodes.back());
	}
	else if(!stricte)
	{
		topSentence = dynamic_pointer_cast<SentenceNode>(baseTop);
		topSentence->content.push_back(sentence);
		path.push(topSentence->content.back());
	}
	return sentence;
}
std::any AstBuilder::visitSentence(HadesParser::SentenceContext *ctx)
{
	std::shared_ptr<SentenceNode> sentence = pushToProgramOrSentence();
	if(!sentence)
		return std::any(0);

	// case 2 or 1
	if(!ctx->sentence().size())
	{
		if(ctx->PIPE())
		{
			pushToProgramOrSentence();
			pseudoVisitWords(ctx->words()[0]);
			path.pop();
			pushToProgramOrSentence();
			pseudoVisitWords(ctx->words()[1]);
			path.pop();
			path.pop();
		}
		else // case with normal sentence just words no pipes
		{
			pseudoVisitWords(ctx->words()[0]);
			path.pop();
		}
	}
	else // case 3
	{
		std::cout << "begin\n";
		for(auto s: ctx->sentence())
		{
			std::cout << "visit\n";
			visit(s);
		}
		std::cout << "end\n";
		path.pop();
	}

	return std::any(1);
}


