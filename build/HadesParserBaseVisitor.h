
// Generated from /home/debian/myhell/HadesParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "HadesParserVisitor.h"


/**
 * This class provides an empty implementation of HadesParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  HadesParserBaseVisitor : public HadesParserVisitor {
public:

  virtual std::any visitProgram(HadesParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSentences(HadesParser::SentencesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPipe(HadesParser::PipeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSentence(HadesParser::SentenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnclosedPipe(HadesParser::UnclosedPipeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(HadesParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarName(HadesParser::VarNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWords(HadesParser::WordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWord(HadesParser::WordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssWords(HadesParser::AssWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssWord(HadesParser::AssWordContext *ctx) override {
    return visitChildren(ctx);
  }


};

