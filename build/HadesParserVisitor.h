
// Generated from /home/debian/myhell/HadesParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "HadesParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by HadesParser.
 */
class  HadesParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by HadesParser.
   */
    virtual std::any visitProgram(HadesParser::ProgramContext *context) = 0;

    virtual std::any visitSentences(HadesParser::SentencesContext *context) = 0;

    virtual std::any visitPipe(HadesParser::PipeContext *context) = 0;

    virtual std::any visitSentence(HadesParser::SentenceContext *context) = 0;

    virtual std::any visitUnclosedPipe(HadesParser::UnclosedPipeContext *context) = 0;

    virtual std::any visitAssignment(HadesParser::AssignmentContext *context) = 0;

    virtual std::any visitVarName(HadesParser::VarNameContext *context) = 0;

    virtual std::any visitWords(HadesParser::WordsContext *context) = 0;

    virtual std::any visitWord(HadesParser::WordContext *context) = 0;

    virtual std::any visitAssWords(HadesParser::AssWordsContext *context) = 0;

    virtual std::any visitAssWord(HadesParser::AssWordContext *context) = 0;


};

