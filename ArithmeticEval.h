#pragma once
#include "ArithmeticLexer.h"
#include "ArithmeticParser.h"
#include "ArithmeticBaseVisitor.h"
#include "Ast.h"

using namespace antlr4;
using namespace antlr4::tree;


class ArithmeticErrorListener : public BaseErrorListener
{
	void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e)
	{

	}
};


class ArithmeticEval : public ArithmeticBaseVisitor
{
	HadesExecutor &exec;

  std::any visitAdd(ArithmeticParser::AddContext *ctx) override {
    return std::any(std::any_cast<int>(visit(ctx->expr()[0])) + std::any_cast<int>(visit(ctx->expr()[1])));
  }

  std::any visitSub(ArithmeticParser::SubContext *ctx) override {
    return std::any(std::any_cast<int>(visit(ctx->expr()[0])) - std::any_cast<int>(visit(ctx->expr()[1])));
  }

  std::any visitMul(ArithmeticParser::MulContext *ctx) override {
    return std::any(std::any_cast<int>(visit(ctx->expr()[0])) * std::any_cast<int>(visit(ctx->expr()[1])));
  }

  std::any visitLower(ArithmeticParser::LowerContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) < std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }

  std::any visitNotequal(ArithmeticParser::NotequalContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) != std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }

  std::any visitInt(ArithmeticParser::IntContext *ctx) override {
    return std::any(std::stoi(ctx->INT()->getText()));
  }

  std::any visitDiv(ArithmeticParser::DivContext *ctx) override {
    return std::any(std::any_cast<int>(visit(ctx->expr()[0])) / std::any_cast<int>(visit(ctx->expr()[1])));
  }

  std::any visitEqual(ArithmeticParser::EqualContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) == std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }

  std::any visitLowerorequal(ArithmeticParser::LowerorequalContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) <= std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }

  std::any visitGreaterorequal(ArithmeticParser::GreaterorequalContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) >= std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }

  std::any visitId(ArithmeticParser::IdContext *ctx) override {
	int ret = 0;
	std::string id = ctx->ID()->getText().substr(1);
	try
	{
		if(auto value = exec.variables.find(id); value != exec.variables.end())
			ret = std::stoi(value->second);
	}
	catch(...)
	{
	}

    return std::any(ret);
  }

  std::any visitModulo(ArithmeticParser::ModuloContext *ctx) override {
    return std::any(std::any_cast<int>(visit(ctx->expr()[0])) % std::any_cast<int>(visit(ctx->expr()[1])));
  }

  std::any visitGreater(ArithmeticParser::GreaterContext *ctx) override {
	  int ret = std::any_cast<int>(visit(ctx->expr()[0])) > std::any_cast<int>(visit(ctx->expr()[1]));
    return std::any(ret);
  }
 
public:
  ArithmeticEval(HadesExecutor &ex): exec(ex) {};
};
