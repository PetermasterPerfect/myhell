
// Generated from /home/debian/myhell/HadesLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  HadesLexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, SEPARATOR = 2, ASSIGN = 3, PIPE = 4, ALPHANUMERIC = 5, RAW_STRING = 6, 
    QUOTED_STRING = 7, UNCLOSED_QUOTED_STRING = 8, ASS_RAW_STRING = 9, ASS_QUOTED_STRING = 10, 
    ASS_UNCLOSED_QUOTED_STRING = 11, END_MARK = 12
  };

  enum {
    VAR_ASSIGNMENT = 1
  };

  explicit HadesLexer(antlr4::CharStream *input);

  ~HadesLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

