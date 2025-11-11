#pragma once
#include "AssHadesParser.h"
#include "AssHadesLexer.h"
#include "AssHadesBaseVisitor.h"
#include "Ast.h"
#include <stack>

using namespace antlr4;
using namespace antlr4::tree;

class AssignmentErrorStrategy : public DefaultErrorStrategy
{
	void recover(Parser *recognizer,  std::exception_ptr e)
	{
		throw "recover";
	}

	Token* recoverInline(Parser *recognizer)
	{
		size_t idx = recognizer->getCurrentToken()->getTokenIndex();
		if(!idx)
			idx=1;
		throw recognizer->getTokenStream()->get(idx-1)->getCharPositionInLine();
	}

	void sync(Parser *recognizer) 
	{ 
	}
};

class AssignmentLexer : public AssHadesLexer
{
public:
	AssignmentLexer(ANTLRInputStream *input): AssHadesLexer(input) {}
	void recover(const LexerNoViableAltException &e)
	{
		std::cerr << "recoverLexer\n";
	}

};

class AssignmentProcessor : public AssHadesBaseVisitor
{

	std::stack<std::shared_ptr<AstNode>> &path;
	//virtual std::any visitAssignments(AssHadesParser::AssignmentsContext *ctx) override;
	virtual std::any visitAssignment(AssHadesParser::AssignmentContext *ctx) override;
	virtual std::any visitWords(AssHadesParser::WordsContext *ctx) override;
public:
	AssignmentProcessor(std::stack<std::shared_ptr<AstNode>> &p): path(p) {}
};
