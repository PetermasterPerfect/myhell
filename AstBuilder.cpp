#include "AstBuilder.h"
#include <iostream>

AstBuilder::AstBuilder(): astTree(std::make_shared<ProgramNode>()) {}

void AstBuilder::printAst()
{
	astTree->print(0);
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

std::any AstBuilder::visitCodeBlock(HadesParser::CodeBlockContext *ctx)
{
	if(ctx->closedCodeBlock())
		visit(ctx->closedCodeBlock());

	if(ctx->unclosedCodeBlock())
		std::cerr << "Unclosed code block\n";
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
	top->codeNodes.push_back(std::make_shared<PipeNode>());
	path.push(top->codeNodes.back());

	auto ss = ctx->sentence();
	for(auto s: ss)
		visit(s);

	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitSentence(HadesParser::SentenceContext *ctx)
{

	std::shared_ptr<AstNode> baseTop = path.top();
	std::shared_ptr<ProgramNode> top;
	if(top = std::dynamic_pointer_cast<ProgramNode>(baseTop))
	{
		top->codeNodes.push_back(std::make_shared<SentenceNode>());
		path.push(top->codeNodes.back());
	}
	else
	{
		std::shared_ptr<PipeNode> topPipe = dynamic_pointer_cast<PipeNode>(baseTop);
		topPipe->sentences.push_back(std::make_shared<SentenceNode>());
		path.push(topPipe->sentences.back());
	}

	if(ctx->assignments())
		visit(ctx->assignments());
	else
	{
		auto wordsVec = ctx->words();
		for(auto v: wordsVec)
			visit(v);
	}
	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitAssignment(HadesParser::AssignmentContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.top());
	std::shared_ptr<AssignmentNode> assignmentN = std::make_shared<AssignmentNode>();
	if(!assignmentN)
		return std::any(0);

	assignmentN->varName = ctx->varName()->getText();
	auto wordVec = ctx->word();
	for(auto v: wordVec)
		assignmentN->value.push_back(v->getText());
	topSentence->atomNodes.push_back(assignmentN);	
	return std::any(1);
}

std::any AstBuilder::visitWords(HadesParser::WordsContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.top());
	//topSentence.atomNode.push_back();
	std::shared_ptr<WordsNode> wordsN = std::make_shared<WordsNode>();
	if(!wordsN)
		return std::any(0);

	if(ctx->LESS())
		wordsN->fileOp = FROMFILE;
	else if(ctx->GREATER())
		wordsN->fileOp = TOFILE;
	
	auto wordVec = ctx->word();
	for(auto v: wordVec)
		wordsN->words.push_back(v->getText());

	topSentence->atomNodes.push_back(wordsN);
	return std::any(1);
}
