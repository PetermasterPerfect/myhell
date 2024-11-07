#include "HadesParser.h"
#include "HadesLexer.h"
#include "HadesBaseVisitor.h"
#include "Ast.h"
#include <queue>

using namespace antlr4;
using namespace antlr4::tree;

class AstBuilder : public HadesBaseVisitor
{
	std::queue<std::shared_ptr<AstNode>> path;
	std::shared_ptr<ProgramNode> astTree;
	//std::vector<std::shared_ptr<AstNode>> functionsDefinitionsNodes;
	
	virtual std::any visitProgram(HadesParser::ProgramContext *ctx) override;
	virtual std::any visitFunctionDefinition(HadesParser::FunctionDefinitionContext *ctx) override;
	virtual std::any visitCodeBlock(HadesParser::CodeBlockContext *ctx) override;
	virtual std::any visitIfStatement(HadesParser::IfStatementContext *ctx) override;
	virtual std::any visitElseIfStatement(HadesParser::ElseIfStatementContext *ctx) override;
	virtual std::any visitElseStatement(HadesParser::ElseStatementContext *ctx) override;
	virtual std::any visitWhileLoop(HadesParser::WhileLoopContext *ctx) override;
	virtual std::any visitPipe(HadesParser::PipeContext *ctx) override;
	virtual std::any visitSentence(HadesParser::SentenceContext *ctx) override;
	virtual std::any visitAssignment(HadesParser::AssignmentContext *ctx) override;
	virtual std::any visitWords(HadesParser::WordsContext *ctx) override;

public:
	AstBuilder();
};

