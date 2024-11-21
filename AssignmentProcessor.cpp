#include "AssignmentProcessor.h"
#include <exception>


std::any AssignmentProcessor::visitAssignment(AssHadesParser::AssignmentContext *ctx)
{
	std::shared_ptr<SentenceNode> topSentence = dynamic_pointer_cast<SentenceNode>(path.top());
	std::shared_ptr<AssignmentNode> assignmentN = std::make_shared<AssignmentNode>();

	assignmentN->varName = ctx->ALPHANUM()->getText();
	path.push(assignmentN);
	auto words = ctx->words();
	for(auto w: words)
		visit(w);
	path.pop();
	topSentence->atomNodes.push_back(assignmentN);	
	return std::any(1);
}

std::any AssignmentProcessor::visitWords(AssHadesParser::WordsContext *ctx)
{
	std::shared_ptr<AstNode> baseTop = path.top();
	std::shared_ptr<SentenceNode> top;
	std::shared_ptr<WordsNode> wordsN = std::make_shared<WordsNode>();
	if(!wordsN)
		return std::any(1);

	if(top = std::dynamic_pointer_cast<SentenceNode>(baseTop))
		top->atomNodes.push_back(wordsN);
	else
	{
		std::shared_ptr<AssignmentNode> topAss = dynamic_pointer_cast<AssignmentNode>(baseTop);
		topAss->value.push_back(wordsN);
	}

	if(ctx->LESS())
		wordsN->fileOp = FROMFILE;
	else if(ctx->GREATER())
		wordsN->fileOp = TOFILE;
	
	auto wordVec = ctx->word();
	for(auto v: wordVec)
		wordsN->words.push_back(v->getText());

	return std::any(1);
}
