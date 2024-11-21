#include "HadesParser.h"
#include "HadesLexer.h"
#include "HadesBaseVisitor.h"
#include "AssignmentProcessor.h"
#include "SentenceProcessor.h"
#include "Ast.h"
#include <stack>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

class AstBuilder : public HadesBaseVisitor
{
	std::stack<std::shared_ptr<AstNode>> path;
	BufferedTokenStream& bufferedTokens;
	std::shared_ptr<ProgramNode> astTree;
	
	virtual std::any visitProgram(HadesParser::ProgramContext *ctx) override;
	virtual std::any visitFunctionDefinition(HadesParser::FunctionDefinitionContext *ctx) override;
	virtual std::any visitIfStatement(HadesParser::IfStatementContext *ctx) override;
	virtual std::any visitElseStatement(HadesParser::ElseStatementContext *ctx) override;
	virtual std::any visitWhileLoop(HadesParser::WhileLoopContext *ctx) override;
	virtual std::any visitPipe(HadesParser::PipeContext *ctx) override;
	virtual std::any visitSentence(HadesParser::SentenceContext *ctx) override;
	//virtual std::any visitAssignment(HadesParser::AssignmentContext *ctx) override;
	//virtual std::any visitWords(HadesParser::WordsContext *ctx) override;

public:
	AstBuilder(BufferedTokenStream&);
	void printAst();
	std::shared_ptr<ProgramNode> getAstTree();
};

