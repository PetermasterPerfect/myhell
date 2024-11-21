#pragma once
#include "SentenceHadesParser.h"
#include "SentenceHadesLexer.h"
#include "SentenceHadesBaseVisitor.h"
#include "Ast.h"
#include <stack>
#include <exception>

using namespace antlr4;
using namespace antlr4::tree;

class SentenceProcessor : public SentenceHadesBaseVisitor
{

	std::stack<std::shared_ptr<AstNode>> &path;
	//virtual std::any visitSentence(SentenceHadesParser::SentenceContext *ctx) override;
	virtual std::any visitWords(SentenceHadesParser::WordsContext *ctx) override;
public:
	SentenceProcessor(std::stack<std::shared_ptr<AstNode>> &p): path(p) {}
};
