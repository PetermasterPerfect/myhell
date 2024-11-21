#include "SentenceProcessor.h"


std::any SentenceProcessor::visitWords(SentenceHadesParser::WordsContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.top());

	std::shared_ptr<WordsNode> wordsN = std::make_shared<WordsNode>();
	if(!wordsN)
		return std::any(0);

	topSentence->atomNodes.push_back(wordsN);

	if(ctx->LESS())
		wordsN->fileOp = FROMFILE;
	else if(ctx->GREATER())
		wordsN->fileOp = TOFILE;
	
	auto wordVec = ctx->word();
	for(auto v: wordVec)
		wordsN->words.push_back(v->getText());

	return std::any(1);
}
