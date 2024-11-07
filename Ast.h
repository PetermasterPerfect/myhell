#include "HadesParser.h"
#include <memory>
#include <vector>

using namespace antlr4;
using namespace antlr4::tree;

enum NodeType {PROGRAM, FUNCTIONDEF, WORDS, ASSIGNMENT, SENTENCE, CONDITIONCODE,
	IFSTATEMENT, WHILELOOP, PIPE};

enum Redirection {NONE, TOFILE, FROMFILE};

class AstNode
{
public:
	NodeType type;
	AstNode(NodeType t): type(t) {}
	virtual ~AstNode()=default;
};

class SentenceNode : public AstNode
{
public:
	std::vector<std::shared_ptr<AstNode>> atomNodes;
	SentenceNode(): AstNode(SENTENCE) {}

};


class AssignmentNode : public AstNode
{
public:
	std::string varName;
	std::vector<std::string> value;
	AssignmentNode(): AstNode(ASSIGNMENT) {}

};

class WordsNode : public AstNode
{
public:
	Redirection fileOp = NONE;
	std::vector<std::string> words;
	WordsNode(): AstNode(WORDS) {}
};

class PipeNode : public AstNode
{
public:
	std::vector<std::shared_ptr<SentenceNode>> sentences;
	PipeNode(): AstNode(PIPE) {}
};

class ProgramNode : public AstNode
{
public:
	std::vector<std::shared_ptr<AstNode>> codeNodes;
	ProgramNode(): AstNode(PROGRAM) {}

};

class FunctionDefNode : public AstNode
{
public:
	std::string name;
	std::vector<std::shared_ptr<AstNode>> codeNodes;
	FunctionDefNode(): AstNode(FUNCTIONDEF){}
};

struct ConditionCode
{
	std::shared_ptr<SentenceNode> condition;
	std::shared_ptr<ProgramNode> code;
};

class IfStatementNode : public AstNode
{
public:
	ConditionCode ifNode;
	std::vector<ConditionCode> elifNodes;
	std::shared_ptr<ProgramNode> elseNode;
	IfStatementNode(): AstNode(IFSTATEMENT) {}
};

class WhileLoopNode : public AstNode
{
public:
	ConditionCode loopContent;
	WhileLoopNode(): AstNode(WHILELOOP) {}
};

