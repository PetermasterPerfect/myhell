#include "AstBuilder.h"
#include <iostream>

AstBuilder::AstBuilder(): astTree(std::make_shared<ProgramNode>()) {}

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
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.front());
	top->codeNodes.push_back(std::make_shared<FunctionDefNode>());
	path.push(top->codeNodes.back());
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
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.front());
	std::shared_ptr<IfStatementNode> buf = std::make_shared<IfStatementNode>();
	if(!buf)
		return std::any(0);

	top->codeNodes.push_back(buf);
	//path.push(top->codeNodes.back());

	visit(ctx->conditionBlock());
	visit(ctx->codeBlock());

	auto elseIfs = ctx->elseIfStatement();
	for(auto v: elseIfs)
		visit(v);
	
	visit(ctx->elseStatement());
	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitElseIfStatement(HadesParser::ElseIfStatementContext *ctx)
{
	std::shared_ptr<IfStatementNode> ifNode = dynamic_pointer_cast<IfStatementNode>(path.front());
	//ifNode->elifNodes.push_back(std::make_shared<ConditionCodeNode>());
	//path.push(ifNode->elifNodes.back());

	visit(ctx->conditionBlock());
	visit(ctx->codeBlock());

	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitElseStatement(HadesParser::ElseStatementContext *ctx)
{
	std::shared_ptr<IfStatementNode> ifNode = dynamic_pointer_cast<IfStatementNode>(path.front());

	ifNode->elseNode = std::make_shared<ProgramNode>();
	path.push(ifNode->elseNode);
	
	visit(ctx->codeBlock());

	path.pop();
	return std::any(1);
}

std::any AstBuilder::visitWhileLoop(HadesParser::WhileLoopContext *ctx)
{
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.front());
	top->codeNodes.push_back(std::make_shared<WhileLoopNode>());
	path.push(top->codeNodes.back());

	visit(ctx->conditionBlock());
	visit(ctx->codeBlock());

	path.pop();

	return std::any(1);
}


std::any AstBuilder::visitPipe(HadesParser::PipeContext *ctx)
{
	std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(path.front());
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

	std::shared_ptr<AstNode> baseTop = path.front();
	if(baseTop->type == PROGRAM)
	{
		std::shared_ptr<ProgramNode> top = dynamic_pointer_cast<ProgramNode>(baseTop);
		top->codeNodes.push_back(std::make_shared<SentenceNode>());
		path.push(top->codeNodes.back());
	}
	else
	{
		std::shared_ptr<PipeNode> top = dynamic_pointer_cast<PipeNode>(baseTop);
		top->sentences.push_back(std::make_shared<SentenceNode>());
		path.push(top->sentences.back());
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
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.front());

	std::shared_ptr<AssignmentNode> assignmentN = std::make_shared<AssignmentNode>();
	
	assignmentN->varName = ctx->varName()->getText();
	auto wordVec = ctx->word();
	for(auto v: wordVec)
		assignmentN->value.push_back(v->getText());
	return std::any(1);
}

std::any AstBuilder::visitWords(HadesParser::WordsContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.front());
	//topSentence.atomNode.push_back();
	std::shared_ptr<WordsNode> wordsN = std::make_shared<WordsNode>();
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
