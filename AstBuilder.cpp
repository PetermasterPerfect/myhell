#include "AstBuilder.h"

AstBuilder::AstBuilder(BufferedTokenStream& t): bufferedTokens(t), astTree(std::make_shared<ProgramNode>()) {}

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

	for(int i=0; i<ctx->children.size(); i++)
		visit(ctx->children[i]);
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


std::any AstBuilder::visitPipe(HadesParser::PipeContext *ctx)
{
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.top());
	std::shared_ptr<PipeNode> pipe = std::make_shared<PipeNode>();
	if(!pipe)
		return std::any(0);

	top->codeNodes.push_back(pipe);
	path.push(pipe);

	auto ss = ctx->sentence();
	for(auto s: ss)
	{
		visit(s);
		size_t lastSenteceSize = pipe->sentences.back()->atomNodes.size();
		if(!lastSenteceSize)
			std::cerr << "Unclosed pipe\n";
	}

	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitSentence(HadesParser::SentenceContext *ctx)
{

	std::shared_ptr<AstNode> baseTop = path.top();
	std::shared_ptr<ProgramNode> topProgram;
	std::shared_ptr<PipeNode> topPipe = nullptr;
	std::shared_ptr<SentenceNode> sentence = std::make_shared<SentenceNode>();
	if(!sentence)
		return std::any(0);

	if(topProgram = std::dynamic_pointer_cast<ProgramNode>(baseTop))
	{
		topProgram->codeNodes.push_back(sentence);
		path.push(topProgram->codeNodes.back());
	}
	else
	{
		topPipe = dynamic_pointer_cast<PipeNode>(baseTop);
		topPipe->sentences.push_back(sentence);
		path.push(topPipe->sentences.back());
	}

	std::string sentenceWithSpaces;
    size_t start = ctx->getStart()->getTokenIndex();
    size_t stop = ctx->getStop()->getTokenIndex();
	std::vector<Token*> tokList = bufferedTokens.getTokens(start, stop);
	for(auto t: tokList)
		sentenceWithSpaces += t->getText();

	ANTLRInputStream input(sentenceWithSpaces);
	AssignmentLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	AssHadesParser parser(&tokens);
	std::shared_ptr<AssignmentErrorStrategy> handler = std::make_shared<AssignmentErrorStrategy>();
	if(!handler)
		return std::any(0);
	parser.setErrorHandler(handler);

	try
	{
		ParseTree *tree = parser.assignments();
		AssignmentProcessor assProc(path);
		assProc.visit(tree);
	}
	catch(size_t pos)
	{
		path.pop();
		if(topProgram)
		{
			if(!sentence->atomNodes.size())
				topProgram->codeNodes.pop_back();

			topProgram->codeNodes.push_back(std::make_shared<SentenceNode>());
			path.push(topProgram->codeNodes.back());
		}
		else
		{
			if(!sentence->atomNodes.size())
				topPipe->sentences.pop_back();

			topPipe->sentences.push_back(std::make_shared<SentenceNode>());
			path.push(topPipe->sentences.back());
		}
		input = ANTLRInputStream(sentenceWithSpaces.substr(pos));
		SentenceHadesLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		SentenceHadesParser parser(&tokens);
		
		ParseTree *tree = parser.sentence();
		SentenceProcessor sentenceProc(path);
		sentenceProc.visit(tree);
	}
	path.pop();

	return std::any(1);
}


