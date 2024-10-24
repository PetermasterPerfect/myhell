
// Generated from /home/debian/myhell/HadesLexer.g4 by ANTLR 4.13.0


#include "HadesLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct HadesLexerStaticData final {
  HadesLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  HadesLexerStaticData(const HadesLexerStaticData&) = delete;
  HadesLexerStaticData(HadesLexerStaticData&&) = delete;
  HadesLexerStaticData& operator=(const HadesLexerStaticData&) = delete;
  HadesLexerStaticData& operator=(HadesLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag hadeslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
HadesLexerStaticData *hadeslexerLexerStaticData = nullptr;

void hadeslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (hadeslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(hadeslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<HadesLexerStaticData>(
    std::vector<std::string>{
      "WS", "SEMI", "NL", "SEPARATOR", "ASSIGN", "PIPE", "ALPHANUMERIC", 
      "RAW_STRING", "NEWLINE_ESCAPE", "STRING_ESCAPE", "QUOTED_STRING", 
      "UNCLOSED_QUOTED_STRING", "ASS_RAW_STRING", "ASS_QUOTED_STRING", "ASS_UNCLOSED_QUOTED_STRING", 
      "END_MARK"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "VAR_ASSIGNMENT"
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
  	4,0,12,155,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,1,0,4,0,36,8,0,11,0,12,0,37,1,1,1,1,1,2,1,2,1,
  	3,1,3,3,3,46,8,3,1,4,1,4,1,5,1,5,1,6,1,6,5,6,54,8,6,10,6,12,6,57,9,6,
  	1,7,4,7,60,8,7,11,7,12,7,61,1,8,1,8,1,8,1,9,1,9,1,9,3,9,70,8,9,1,10,1,
  	10,1,10,5,10,75,8,10,10,10,12,10,78,9,10,1,10,1,10,1,10,1,10,5,10,84,
  	8,10,10,10,12,10,87,9,10,1,10,3,10,90,8,10,1,11,1,11,1,11,5,11,95,8,11,
  	10,11,12,11,98,9,11,1,11,1,11,1,11,5,11,103,8,11,10,11,12,11,106,9,11,
  	3,11,108,8,11,1,12,4,12,111,8,12,11,12,12,12,112,1,13,1,13,1,13,5,13,
  	118,8,13,10,13,12,13,121,9,13,1,13,1,13,1,13,1,13,5,13,127,8,13,10,13,
  	12,13,130,9,13,1,13,3,13,133,8,13,1,14,1,14,1,14,5,14,138,8,14,10,14,
  	12,14,141,9,14,1,14,1,14,1,14,5,14,146,8,14,10,14,12,14,149,9,14,3,14,
  	151,8,14,1,15,3,15,154,8,15,0,0,16,2,1,4,0,6,0,8,2,10,3,12,4,14,5,16,
  	6,18,0,20,0,22,7,24,8,26,9,28,10,30,11,32,12,2,0,1,8,2,0,9,9,32,32,2,
  	0,10,10,13,13,2,0,65,90,97,122,3,0,48,57,65,90,97,122,9,0,9,10,13,13,
  	32,32,34,34,39,39,59,59,61,61,92,92,124,124,2,0,39,39,92,92,2,0,34,34,
  	92,92,3,0,10,10,13,13,59,59,175,0,2,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,
  	0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,1,26,
  	1,0,0,0,1,28,1,0,0,0,1,30,1,0,0,0,1,32,1,0,0,0,2,35,1,0,0,0,4,39,1,0,
  	0,0,6,41,1,0,0,0,8,45,1,0,0,0,10,47,1,0,0,0,12,49,1,0,0,0,14,51,1,0,0,
  	0,16,59,1,0,0,0,18,63,1,0,0,0,20,69,1,0,0,0,22,89,1,0,0,0,24,107,1,0,
  	0,0,26,110,1,0,0,0,28,132,1,0,0,0,30,150,1,0,0,0,32,153,1,0,0,0,34,36,
  	7,0,0,0,35,34,1,0,0,0,36,37,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,38,3,
  	1,0,0,0,39,40,5,59,0,0,40,5,1,0,0,0,41,42,7,1,0,0,42,7,1,0,0,0,43,46,
  	3,4,1,0,44,46,3,6,2,0,45,43,1,0,0,0,45,44,1,0,0,0,46,9,1,0,0,0,47,48,
  	5,61,0,0,48,11,1,0,0,0,49,50,5,124,0,0,50,13,1,0,0,0,51,55,7,2,0,0,52,
  	54,7,3,0,0,53,52,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,
  	15,1,0,0,0,57,55,1,0,0,0,58,60,8,4,0,0,59,58,1,0,0,0,60,61,1,0,0,0,61,
  	59,1,0,0,0,61,62,1,0,0,0,62,17,1,0,0,0,63,64,5,92,0,0,64,65,7,1,0,0,65,
  	19,1,0,0,0,66,67,5,92,0,0,67,70,9,0,0,0,68,70,3,18,8,0,69,66,1,0,0,0,
  	69,68,1,0,0,0,70,21,1,0,0,0,71,76,5,39,0,0,72,75,3,20,9,0,73,75,8,5,0,
  	0,74,72,1,0,0,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,
  	0,77,79,1,0,0,0,78,76,1,0,0,0,79,90,5,39,0,0,80,85,5,34,0,0,81,84,3,20,
  	9,0,82,84,8,6,0,0,83,81,1,0,0,0,83,82,1,0,0,0,84,87,1,0,0,0,85,83,1,0,
  	0,0,85,86,1,0,0,0,86,88,1,0,0,0,87,85,1,0,0,0,88,90,5,34,0,0,89,71,1,
  	0,0,0,89,80,1,0,0,0,90,23,1,0,0,0,91,96,5,39,0,0,92,95,3,20,9,0,93,95,
  	8,5,0,0,94,92,1,0,0,0,94,93,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,
  	1,0,0,0,97,108,1,0,0,0,98,96,1,0,0,0,99,104,5,34,0,0,100,103,3,20,9,0,
  	101,103,8,6,0,0,102,100,1,0,0,0,102,101,1,0,0,0,103,106,1,0,0,0,104,102,
  	1,0,0,0,104,105,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,107,91,1,0,0,
  	0,107,99,1,0,0,0,108,25,1,0,0,0,109,111,8,4,0,0,110,109,1,0,0,0,111,112,
  	1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,27,1,0,0,0,114,119,5,39,0,
  	0,115,118,3,20,9,0,116,118,8,5,0,0,117,115,1,0,0,0,117,116,1,0,0,0,118,
  	121,1,0,0,0,119,117,1,0,0,0,119,120,1,0,0,0,120,122,1,0,0,0,121,119,1,
  	0,0,0,122,133,5,39,0,0,123,128,5,34,0,0,124,127,3,20,9,0,125,127,8,6,
  	0,0,126,124,1,0,0,0,126,125,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,
  	129,1,0,0,0,129,131,1,0,0,0,130,128,1,0,0,0,131,133,5,34,0,0,132,114,
  	1,0,0,0,132,123,1,0,0,0,133,29,1,0,0,0,134,139,5,39,0,0,135,138,3,20,
  	9,0,136,138,8,5,0,0,137,135,1,0,0,0,137,136,1,0,0,0,138,141,1,0,0,0,139,
  	137,1,0,0,0,139,140,1,0,0,0,140,151,1,0,0,0,141,139,1,0,0,0,142,147,5,
  	34,0,0,143,146,3,20,9,0,144,146,8,6,0,0,145,143,1,0,0,0,145,144,1,0,0,
  	0,146,149,1,0,0,0,147,145,1,0,0,0,147,148,1,0,0,0,148,151,1,0,0,0,149,
  	147,1,0,0,0,150,134,1,0,0,0,150,142,1,0,0,0,151,31,1,0,0,0,152,154,7,
  	7,0,0,153,152,1,0,0,0,154,33,1,0,0,0,29,0,1,37,45,55,61,69,74,76,83,85,
  	89,94,96,102,104,107,112,117,119,126,128,132,137,139,145,147,150,153,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  hadeslexerLexerStaticData = staticData.release();
}

}

HadesLexer::HadesLexer(CharStream *input) : Lexer(input) {
  HadesLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *hadeslexerLexerStaticData->atn, hadeslexerLexerStaticData->decisionToDFA, hadeslexerLexerStaticData->sharedContextCache);
}

HadesLexer::~HadesLexer() {
  delete _interpreter;
}

std::string HadesLexer::getGrammarFileName() const {
  return "HadesLexer.g4";
}

const std::vector<std::string>& HadesLexer::getRuleNames() const {
  return hadeslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& HadesLexer::getChannelNames() const {
  return hadeslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& HadesLexer::getModeNames() const {
  return hadeslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& HadesLexer::getVocabulary() const {
  return hadeslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView HadesLexer::getSerializedATN() const {
  return hadeslexerLexerStaticData->serializedATN;
}

const atn::ATN& HadesLexer::getATN() const {
  return *hadeslexerLexerStaticData->atn;
}




void HadesLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  hadeslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(hadeslexerLexerOnceFlag, hadeslexerLexerInitialize);
#endif
}
