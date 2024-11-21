#pragma once
#include "HadesParser.h"
//#include "HadesExecutor.h"
#include <memory>
#include <vector>
#include <unordered_map>

class HadesExecutor;

using namespace antlr4;
using namespace antlr4::tree;

enum NodeType {PROGRAM, FUNCTIONDEF, WORDS, ASSIGNMENT, SENTENCE, CONDITIONCODE,
	IFSTATEMENT, WHILELOOP, PIPE};

enum Redirection {NONE, TOFILE, FROMFILE};


std::string processWords(std::vector<std::string>);
bool isWordQuoted(std::string);

class AstNode
{
public:
	NodeType type;
	AstNode(NodeType t): type(t) {}
	virtual ~AstNode()=default;
	virtual void print(int)=0;
	virtual void execute(HadesExecutor&)=0;
};

class SentenceNode : public AstNode
{
public:
	std::vector<std::shared_ptr<AstNode>> atomNodes;
	SentenceNode(): AstNode(SENTENCE) {}
	void print(int) override;
	void execute(HadesExecutor&) override;
};

class WordsNode : public AstNode
{
public:
	Redirection fileOp = NONE;
	std::vector<std::string> words;
	WordsNode(): AstNode(WORDS) {}
	void print(int) override;
	void execute(HadesExecutor&) override;
};

class AssignmentNode : public AstNode
{
public:
	std::string varName;
	std::vector<std::shared_ptr<WordsNode>> value;
	AssignmentNode(): AstNode(ASSIGNMENT) {}
	void print(int) override;
	void execute(HadesExecutor&) override;

};

class PipeNode : public AstNode
{
public:
	std::vector<std::shared_ptr<SentenceNode>> sentences;
	PipeNode(): AstNode(PIPE) {}
	void print(int) override;
	void execute(HadesExecutor&) override;
};

class ProgramNode : public AstNode
{
public:
	std::vector<std::shared_ptr<AstNode>> codeNodes;
	ProgramNode(): AstNode(PROGRAM) {}
	void print(int) override;
	void execute(HadesExecutor&) override;

};

class FunctionDefNode : public AstNode
{
public:
	std::string name;
	std::shared_ptr<ProgramNode> body;
	FunctionDefNode(): AstNode(FUNCTIONDEF), body(std::make_shared<ProgramNode>()){}
	void print(int) override;
	void execute(HadesExecutor&) override;
};

class IfStatementNode : public AstNode
{
public:
	std::vector<std::shared_ptr<ProgramNode>> condCodeNodes;
	std::shared_ptr<ProgramNode> elseNode;
	IfStatementNode(size_t sz): AstNode(IFSTATEMENT), condCodeNodes(sz), elseNode(std::make_shared<ProgramNode>())
	{
		for(size_t i=0; i<sz; i++)
			condCodeNodes[i] = std::make_shared<ProgramNode>();
	}
	
	bool noNull()
	{
		for(auto v: condCodeNodes)
			if(!v) return false;
		return true;
	}

	void print(int) override;
	void execute(HadesExecutor&) override;
};

class WhileLoopNode : public AstNode
{
public:
	std::shared_ptr<ProgramNode> condition;
	std::shared_ptr<ProgramNode> body;
	WhileLoopNode(): AstNode(WHILELOOP), 
		condition(std::make_shared<ProgramNode>()),
		body(std::make_shared<ProgramNode>()){}
	void print(int) override;
	void execute(HadesExecutor&) override;
};

class HadesExecutor
{
public:
	std::unordered_map<std::string, std::string> variables;
	std::unordered_map<std::string,	std::shared_ptr<ProgramNode>> functions;

	HadesExecutor(){}
};

