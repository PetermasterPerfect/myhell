
// Generated from /home/debian/myhell/HadesParser.g4 by ANTLR 4.13.0


#include "HadesParserVisitor.h"

#include "HadesParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct HadesParserStaticData final {
  HadesParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  HadesParserStaticData(const HadesParserStaticData&) = delete;
  HadesParserStaticData(HadesParserStaticData&&) = delete;
  HadesParserStaticData& operator=(const HadesParserStaticData&) = delete;
  HadesParserStaticData& operator=(HadesParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag hadesparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
HadesParserStaticData *hadesparserParserStaticData = nullptr;

void hadesparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (hadesparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(hadesparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<HadesParserStaticData>(
    std::vector<std::string>{
      "program", "sentences", "pipe", "sentence", "unclosedPipe", "assignment", 
      "varName", "words", "word", "assWords", "assWord"
    },
    std::vector<std::string>{
      "", "", "", "'='", "'|'"
    },
    std::vector<std::string>{
      "", "WS", "SEPARATOR", "ASSIGN", "PIPE", "ALPHANUMERIC", "RAW_STRING", 
      "QUOTED_STRING", "UNCLOSED_QUOTED_STRING", "ASS_RAW_STRING", "ASS_QUOTED_STRING", 
      "ASS_UNCLOSED_QUOTED_STRING", "END_MARK"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,104,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,1,0,1,1,1,1,3,1,27,8,1,1,1,1,1,1,
  	1,3,1,32,8,1,5,1,34,8,1,10,1,12,1,37,9,1,1,1,3,1,40,8,1,1,2,1,2,1,2,1,
  	2,1,2,5,2,47,8,2,10,2,12,2,50,9,2,1,3,3,3,53,8,3,1,3,1,3,1,3,5,3,58,8,
  	3,10,3,12,3,61,9,3,1,3,3,3,64,8,3,1,3,3,3,67,8,3,1,3,1,3,3,3,71,8,3,3,
  	3,73,8,3,1,4,1,4,1,4,1,5,1,5,1,5,4,5,81,8,5,11,5,12,5,82,1,6,4,6,86,8,
  	6,11,6,12,6,87,1,7,4,7,91,8,7,11,7,12,7,92,1,8,1,8,1,9,4,9,98,8,9,11,
  	9,12,9,99,1,10,1,10,1,10,0,0,11,0,2,4,6,8,10,12,14,16,18,20,0,2,1,0,5,
  	8,1,0,9,11,107,0,22,1,0,0,0,2,26,1,0,0,0,4,41,1,0,0,0,6,72,1,0,0,0,8,
  	74,1,0,0,0,10,77,1,0,0,0,12,85,1,0,0,0,14,90,1,0,0,0,16,94,1,0,0,0,18,
  	97,1,0,0,0,20,101,1,0,0,0,22,23,3,2,1,0,23,1,1,0,0,0,24,27,3,6,3,0,25,
  	27,3,4,2,0,26,24,1,0,0,0,26,25,1,0,0,0,27,35,1,0,0,0,28,31,5,2,0,0,29,
  	32,3,6,3,0,30,32,3,4,2,0,31,29,1,0,0,0,31,30,1,0,0,0,32,34,1,0,0,0,33,
  	28,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,35,36,1,0,0,0,36,39,1,0,0,0,37,
  	35,1,0,0,0,38,40,5,2,0,0,39,38,1,0,0,0,39,40,1,0,0,0,40,3,1,0,0,0,41,
  	42,3,6,3,0,42,43,5,4,0,0,43,48,3,6,3,0,44,45,5,4,0,0,45,47,3,6,3,0,46,
  	44,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,5,1,0,0,0,50,
  	48,1,0,0,0,51,53,5,1,0,0,52,51,1,0,0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,
  	59,3,14,7,0,55,56,5,1,0,0,56,58,3,14,7,0,57,55,1,0,0,0,58,61,1,0,0,0,
  	59,57,1,0,0,0,59,60,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,62,64,5,1,0,0,
  	63,62,1,0,0,0,63,64,1,0,0,0,64,73,1,0,0,0,65,67,5,1,0,0,66,65,1,0,0,0,
  	66,67,1,0,0,0,67,68,1,0,0,0,68,70,3,10,5,0,69,71,5,1,0,0,70,69,1,0,0,
  	0,70,71,1,0,0,0,71,73,1,0,0,0,72,52,1,0,0,0,72,66,1,0,0,0,73,7,1,0,0,
  	0,74,75,3,16,8,0,75,76,5,4,0,0,76,9,1,0,0,0,77,78,3,12,6,0,78,80,5,3,
  	0,0,79,81,3,16,8,0,80,79,1,0,0,0,81,82,1,0,0,0,82,80,1,0,0,0,82,83,1,
  	0,0,0,83,11,1,0,0,0,84,86,5,5,0,0,85,84,1,0,0,0,86,87,1,0,0,0,87,85,1,
  	0,0,0,87,88,1,0,0,0,88,13,1,0,0,0,89,91,3,16,8,0,90,89,1,0,0,0,91,92,
  	1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,15,1,0,0,0,94,95,7,0,0,0,95,17,
  	1,0,0,0,96,98,3,20,10,0,97,96,1,0,0,0,98,99,1,0,0,0,99,97,1,0,0,0,99,
  	100,1,0,0,0,100,19,1,0,0,0,101,102,7,1,0,0,102,21,1,0,0,0,15,26,31,35,
  	39,48,52,59,63,66,70,72,82,87,92,99
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  hadesparserParserStaticData = staticData.release();
}

}

HadesParser::HadesParser(TokenStream *input) : HadesParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

HadesParser::HadesParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  HadesParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *hadesparserParserStaticData->atn, hadesparserParserStaticData->decisionToDFA, hadesparserParserStaticData->sharedContextCache, options);
}

HadesParser::~HadesParser() {
  delete _interpreter;
}

const atn::ATN& HadesParser::getATN() const {
  return *hadesparserParserStaticData->atn;
}

std::string HadesParser::getGrammarFileName() const {
  return "HadesParser.g4";
}

const std::vector<std::string>& HadesParser::getRuleNames() const {
  return hadesparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& HadesParser::getVocabulary() const {
  return hadesparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView HadesParser::getSerializedATN() const {
  return hadesparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

HadesParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HadesParser::SentencesContext* HadesParser::ProgramContext::sentences() {
  return getRuleContext<HadesParser::SentencesContext>(0);
}


size_t HadesParser::ProgramContext::getRuleIndex() const {
  return HadesParser::RuleProgram;
}


std::any HadesParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::ProgramContext* HadesParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, HadesParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    sentences();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SentencesContext ------------------------------------------------------------------

HadesParser::SentencesContext::SentencesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HadesParser::SentenceContext *> HadesParser::SentencesContext::sentence() {
  return getRuleContexts<HadesParser::SentenceContext>();
}

HadesParser::SentenceContext* HadesParser::SentencesContext::sentence(size_t i) {
  return getRuleContext<HadesParser::SentenceContext>(i);
}

std::vector<HadesParser::PipeContext *> HadesParser::SentencesContext::pipe() {
  return getRuleContexts<HadesParser::PipeContext>();
}

HadesParser::PipeContext* HadesParser::SentencesContext::pipe(size_t i) {
  return getRuleContext<HadesParser::PipeContext>(i);
}

std::vector<tree::TerminalNode *> HadesParser::SentencesContext::SEPARATOR() {
  return getTokens(HadesParser::SEPARATOR);
}

tree::TerminalNode* HadesParser::SentencesContext::SEPARATOR(size_t i) {
  return getToken(HadesParser::SEPARATOR, i);
}


size_t HadesParser::SentencesContext::getRuleIndex() const {
  return HadesParser::RuleSentences;
}


std::any HadesParser::SentencesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitSentences(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::SentencesContext* HadesParser::sentences() {
  SentencesContext *_localctx = _tracker.createInstance<SentencesContext>(_ctx, getState());
  enterRule(_localctx, 2, HadesParser::RuleSentences);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(26);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(24);
      sentence();
      break;
    }

    case 2: {
      setState(25);
      pipe();
      break;
    }

    default:
      break;
    }
    setState(35);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(28);
        match(HadesParser::SEPARATOR);
        setState(31);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(29);
          sentence();
          break;
        }

        case 2: {
          setState(30);
          pipe();
          break;
        }

        default:
          break;
        } 
      }
      setState(37);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HadesParser::SEPARATOR) {
      setState(38);
      match(HadesParser::SEPARATOR);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PipeContext ------------------------------------------------------------------

HadesParser::PipeContext::PipeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HadesParser::SentenceContext *> HadesParser::PipeContext::sentence() {
  return getRuleContexts<HadesParser::SentenceContext>();
}

HadesParser::SentenceContext* HadesParser::PipeContext::sentence(size_t i) {
  return getRuleContext<HadesParser::SentenceContext>(i);
}

std::vector<tree::TerminalNode *> HadesParser::PipeContext::PIPE() {
  return getTokens(HadesParser::PIPE);
}

tree::TerminalNode* HadesParser::PipeContext::PIPE(size_t i) {
  return getToken(HadesParser::PIPE, i);
}


size_t HadesParser::PipeContext::getRuleIndex() const {
  return HadesParser::RulePipe;
}


std::any HadesParser::PipeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitPipe(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::PipeContext* HadesParser::pipe() {
  PipeContext *_localctx = _tracker.createInstance<PipeContext>(_ctx, getState());
  enterRule(_localctx, 4, HadesParser::RulePipe);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    sentence();
    setState(42);
    match(HadesParser::PIPE);
    setState(43);
    sentence();
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HadesParser::PIPE) {
      setState(44);
      match(HadesParser::PIPE);
      setState(45);
      sentence();
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SentenceContext ------------------------------------------------------------------

HadesParser::SentenceContext::SentenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HadesParser::WordsContext *> HadesParser::SentenceContext::words() {
  return getRuleContexts<HadesParser::WordsContext>();
}

HadesParser::WordsContext* HadesParser::SentenceContext::words(size_t i) {
  return getRuleContext<HadesParser::WordsContext>(i);
}

std::vector<tree::TerminalNode *> HadesParser::SentenceContext::WS() {
  return getTokens(HadesParser::WS);
}

tree::TerminalNode* HadesParser::SentenceContext::WS(size_t i) {
  return getToken(HadesParser::WS, i);
}

HadesParser::AssignmentContext* HadesParser::SentenceContext::assignment() {
  return getRuleContext<HadesParser::AssignmentContext>(0);
}


size_t HadesParser::SentenceContext::getRuleIndex() const {
  return HadesParser::RuleSentence;
}


std::any HadesParser::SentenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitSentence(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::SentenceContext* HadesParser::sentence() {
  SentenceContext *_localctx = _tracker.createInstance<SentenceContext>(_ctx, getState());
  enterRule(_localctx, 6, HadesParser::RuleSentence);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(72);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(52);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == HadesParser::WS) {
        setState(51);
        match(HadesParser::WS);
      }
      setState(54);
      words();
      setState(59);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(55);
          match(HadesParser::WS);
          setState(56);
          words(); 
        }
        setState(61);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
      setState(63);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == HadesParser::WS) {
        setState(62);
        match(HadesParser::WS);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(66);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == HadesParser::WS) {
        setState(65);
        match(HadesParser::WS);
      }
      setState(68);
      assignment();
      setState(70);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == HadesParser::WS) {
        setState(69);
        match(HadesParser::WS);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnclosedPipeContext ------------------------------------------------------------------

HadesParser::UnclosedPipeContext::UnclosedPipeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HadesParser::WordContext* HadesParser::UnclosedPipeContext::word() {
  return getRuleContext<HadesParser::WordContext>(0);
}

tree::TerminalNode* HadesParser::UnclosedPipeContext::PIPE() {
  return getToken(HadesParser::PIPE, 0);
}


size_t HadesParser::UnclosedPipeContext::getRuleIndex() const {
  return HadesParser::RuleUnclosedPipe;
}


std::any HadesParser::UnclosedPipeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitUnclosedPipe(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::UnclosedPipeContext* HadesParser::unclosedPipe() {
  UnclosedPipeContext *_localctx = _tracker.createInstance<UnclosedPipeContext>(_ctx, getState());
  enterRule(_localctx, 8, HadesParser::RuleUnclosedPipe);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    word();
    setState(75);
    match(HadesParser::PIPE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

HadesParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HadesParser::VarNameContext* HadesParser::AssignmentContext::varName() {
  return getRuleContext<HadesParser::VarNameContext>(0);
}

tree::TerminalNode* HadesParser::AssignmentContext::ASSIGN() {
  return getToken(HadesParser::ASSIGN, 0);
}

std::vector<HadesParser::WordContext *> HadesParser::AssignmentContext::word() {
  return getRuleContexts<HadesParser::WordContext>();
}

HadesParser::WordContext* HadesParser::AssignmentContext::word(size_t i) {
  return getRuleContext<HadesParser::WordContext>(i);
}


size_t HadesParser::AssignmentContext::getRuleIndex() const {
  return HadesParser::RuleAssignment;
}


std::any HadesParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::AssignmentContext* HadesParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 10, HadesParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    varName();
    setState(78);
    match(HadesParser::ASSIGN);
    setState(80); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(79);
      word();
      setState(82); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 480) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNameContext ------------------------------------------------------------------

HadesParser::VarNameContext::VarNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> HadesParser::VarNameContext::ALPHANUMERIC() {
  return getTokens(HadesParser::ALPHANUMERIC);
}

tree::TerminalNode* HadesParser::VarNameContext::ALPHANUMERIC(size_t i) {
  return getToken(HadesParser::ALPHANUMERIC, i);
}


size_t HadesParser::VarNameContext::getRuleIndex() const {
  return HadesParser::RuleVarName;
}


std::any HadesParser::VarNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitVarName(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::VarNameContext* HadesParser::varName() {
  VarNameContext *_localctx = _tracker.createInstance<VarNameContext>(_ctx, getState());
  enterRule(_localctx, 12, HadesParser::RuleVarName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(84);
      match(HadesParser::ALPHANUMERIC);
      setState(87); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HadesParser::ALPHANUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordsContext ------------------------------------------------------------------

HadesParser::WordsContext::WordsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HadesParser::WordContext *> HadesParser::WordsContext::word() {
  return getRuleContexts<HadesParser::WordContext>();
}

HadesParser::WordContext* HadesParser::WordsContext::word(size_t i) {
  return getRuleContext<HadesParser::WordContext>(i);
}


size_t HadesParser::WordsContext::getRuleIndex() const {
  return HadesParser::RuleWords;
}


std::any HadesParser::WordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitWords(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::WordsContext* HadesParser::words() {
  WordsContext *_localctx = _tracker.createInstance<WordsContext>(_ctx, getState());
  enterRule(_localctx, 14, HadesParser::RuleWords);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(89);
      word();
      setState(92); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 480) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordContext ------------------------------------------------------------------

HadesParser::WordContext::WordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HadesParser::WordContext::RAW_STRING() {
  return getToken(HadesParser::RAW_STRING, 0);
}

tree::TerminalNode* HadesParser::WordContext::ALPHANUMERIC() {
  return getToken(HadesParser::ALPHANUMERIC, 0);
}

tree::TerminalNode* HadesParser::WordContext::QUOTED_STRING() {
  return getToken(HadesParser::QUOTED_STRING, 0);
}

tree::TerminalNode* HadesParser::WordContext::UNCLOSED_QUOTED_STRING() {
  return getToken(HadesParser::UNCLOSED_QUOTED_STRING, 0);
}


size_t HadesParser::WordContext::getRuleIndex() const {
  return HadesParser::RuleWord;
}


std::any HadesParser::WordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitWord(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::WordContext* HadesParser::word() {
  WordContext *_localctx = _tracker.createInstance<WordContext>(_ctx, getState());
  enterRule(_localctx, 16, HadesParser::RuleWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 480) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssWordsContext ------------------------------------------------------------------

HadesParser::AssWordsContext::AssWordsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HadesParser::AssWordContext *> HadesParser::AssWordsContext::assWord() {
  return getRuleContexts<HadesParser::AssWordContext>();
}

HadesParser::AssWordContext* HadesParser::AssWordsContext::assWord(size_t i) {
  return getRuleContext<HadesParser::AssWordContext>(i);
}


size_t HadesParser::AssWordsContext::getRuleIndex() const {
  return HadesParser::RuleAssWords;
}


std::any HadesParser::AssWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitAssWords(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::AssWordsContext* HadesParser::assWords() {
  AssWordsContext *_localctx = _tracker.createInstance<AssWordsContext>(_ctx, getState());
  enterRule(_localctx, 18, HadesParser::RuleAssWords);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(96);
      assWord();
      setState(99); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3584) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssWordContext ------------------------------------------------------------------

HadesParser::AssWordContext::AssWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HadesParser::AssWordContext::ASS_RAW_STRING() {
  return getToken(HadesParser::ASS_RAW_STRING, 0);
}

tree::TerminalNode* HadesParser::AssWordContext::ASS_QUOTED_STRING() {
  return getToken(HadesParser::ASS_QUOTED_STRING, 0);
}

tree::TerminalNode* HadesParser::AssWordContext::ASS_UNCLOSED_QUOTED_STRING() {
  return getToken(HadesParser::ASS_UNCLOSED_QUOTED_STRING, 0);
}


size_t HadesParser::AssWordContext::getRuleIndex() const {
  return HadesParser::RuleAssWord;
}


std::any HadesParser::AssWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HadesParserVisitor*>(visitor))
    return parserVisitor->visitAssWord(this);
  else
    return visitor->visitChildren(this);
}

HadesParser::AssWordContext* HadesParser::assWord() {
  AssWordContext *_localctx = _tracker.createInstance<AssWordContext>(_ctx, getState());
  enterRule(_localctx, 20, HadesParser::RuleAssWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3584) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void HadesParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  hadesparserParserInitialize();
#else
  ::antlr4::internal::call_once(hadesparserParserOnceFlag, hadesparserParserInitialize);
#endif
}
