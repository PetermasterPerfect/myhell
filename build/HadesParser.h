
// Generated from /home/debian/myhell/HadesParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  HadesParser : public antlr4::Parser {
public:
  enum {
    WS = 1, SEPARATOR = 2, ASSIGN = 3, PIPE = 4, ALPHANUMERIC = 5, RAW_STRING = 6, 
    QUOTED_STRING = 7, UNCLOSED_QUOTED_STRING = 8, ASS_RAW_STRING = 9, ASS_QUOTED_STRING = 10, 
    ASS_UNCLOSED_QUOTED_STRING = 11, END_MARK = 12
  };

  enum {
    RuleProgram = 0, RuleSentences = 1, RulePipe = 2, RuleSentence = 3, 
    RuleUnclosedPipe = 4, RuleAssignment = 5, RuleVarName = 6, RuleWords = 7, 
    RuleWord = 8, RuleAssWords = 9, RuleAssWord = 10
  };

  explicit HadesParser(antlr4::TokenStream *input);

  HadesParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~HadesParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class SentencesContext;
  class PipeContext;
  class SentenceContext;
  class UnclosedPipeContext;
  class AssignmentContext;
  class VarNameContext;
  class WordsContext;
  class WordContext;
  class AssWordsContext;
  class AssWordContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SentencesContext *sentences();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  SentencesContext : public antlr4::ParserRuleContext {
  public:
    SentencesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SentenceContext *> sentence();
    SentenceContext* sentence(size_t i);
    std::vector<PipeContext *> pipe();
    PipeContext* pipe(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEPARATOR();
    antlr4::tree::TerminalNode* SEPARATOR(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SentencesContext* sentences();

  class  PipeContext : public antlr4::ParserRuleContext {
  public:
    PipeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SentenceContext *> sentence();
    SentenceContext* sentence(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PIPE();
    antlr4::tree::TerminalNode* PIPE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PipeContext* pipe();

  class  SentenceContext : public antlr4::ParserRuleContext {
  public:
    SentenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WordsContext *> words();
    WordsContext* words(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    AssignmentContext *assignment();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SentenceContext* sentence();

  class  UnclosedPipeContext : public antlr4::ParserRuleContext {
  public:
    UnclosedPipeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WordContext *word();
    antlr4::tree::TerminalNode *PIPE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnclosedPipeContext* unclosedPipe();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarNameContext *varName();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<WordContext *> word();
    WordContext* word(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  VarNameContext : public antlr4::ParserRuleContext {
  public:
    VarNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ALPHANUMERIC();
    antlr4::tree::TerminalNode* ALPHANUMERIC(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarNameContext* varName();

  class  WordsContext : public antlr4::ParserRuleContext {
  public:
    WordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WordContext *> word();
    WordContext* word(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WordsContext* words();

  class  WordContext : public antlr4::ParserRuleContext {
  public:
    WordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAW_STRING();
    antlr4::tree::TerminalNode *ALPHANUMERIC();
    antlr4::tree::TerminalNode *QUOTED_STRING();
    antlr4::tree::TerminalNode *UNCLOSED_QUOTED_STRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WordContext* word();

  class  AssWordsContext : public antlr4::ParserRuleContext {
  public:
    AssWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssWordContext *> assWord();
    AssWordContext* assWord(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssWordsContext* assWords();

  class  AssWordContext : public antlr4::ParserRuleContext {
  public:
    AssWordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASS_RAW_STRING();
    antlr4::tree::TerminalNode *ASS_QUOTED_STRING();
    antlr4::tree::TerminalNode *ASS_UNCLOSED_QUOTED_STRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssWordContext* assWord();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

