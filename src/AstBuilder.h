#include "HadesParser.h"
#include "HadesLexer.h"
#include "HadesBaseVisitor.h"
#include "AssignmentProcessor.h"
#include "SentenceProcessor.h"
#include "Ast.h"
#include <stack>
#include <iostream>
#include <stdexcept>

using namespace antlr4;
using namespace antlr4::tree;


class LexerErrorListener : public BaseErrorListener
{
	void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e)
	{
		throw std::runtime_error(msg);
	}

	void reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
		  const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs)
	{
		throw std::runtime_error("Ambiguity");
	}
};



class AstBuilderErrorListener : public BaseErrorListener
{
	void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e)
	{

	}
};

class AstBuilderErrorStrategy : public DefaultErrorStrategy
{
	void recover(Parser *recognizer,  std::exception_ptr e)
	{
		throw std::runtime_error("recover");
	}

	Token* recoverInline(Parser *recognizer)
	{
		throw std::runtime_error("recoverInline");
	}

	void sync(Parser *recognizer) 
	{ 
	}
};


class AstBuilder : public HadesBaseVisitor
{
	std::stack<std::shared_ptr<AstNode>> path;
	BufferedTokenStream& bufferedTokens;
	std::shared_ptr<ProgramNode> astTree;
	
	bool isConditionBlockOK(HadesParser::ConditionBlockContext *ctx);
	bool isCodeBlockOK(HadesParser::CodeBlockContext *ctx);

	virtual std::any visitProgram(HadesParser::ProgramContext *ctx) override;
	virtual std::any visitFunctionDefinition(HadesParser::FunctionDefinitionContext *ctx) override;
	virtual std::any visitIfStatement(HadesParser::IfStatementContext *ctx) override;
	virtual std::any visitElseStatement(HadesParser::ElseStatementContext *ctx) override;
	virtual std::any visitWhileLoop(HadesParser::WhileLoopContext *ctx) override;
	virtual std::any visitSentence(HadesParser::SentenceContext *ctx) override;
	
	void runAsssignmentParser(std::string sentence);
	void pseudoVisitWords(HadesParser::WordsContext *ctx);
	std::string recoverSpacesFromTokens(HadesParser::WordsContext *ctx);
	std::shared_ptr<SentenceNode> pushToProgramOrSentence(bool strict=false);

public:
	AstBuilder(BufferedTokenStream&);
	void printAst();
	std::shared_ptr<ProgramNode> getAstTree();
};

