#include "Ast.h"

std::string tabs(int i)
{
	return std::string(i*2, ' ');
}

void SentenceNode::print(int i)
{
	std::cout << tabs(i) << "(SentenceNode)" << std::endl;
	for(auto atom: atomNodes)
		atom->print(i+1);
	std::cout << std::endl;
}

void AssignmentNode::print(int i)
{
	std::cout << tabs(i) << "(Assignment) " << varName << "=";
	for(auto v: value)
		std::cout << v;
}

void WordsNode::print(int i)
{
	std::cout << tabs(i) << "(Words) ";
	if(fileOp == TOFILE)
		std::cout << ">";
	else if(fileOp == FROMFILE)
		std::cout << "<";

	for(auto w: words)
		std::cout << w << std::endl;
}

void PipeNode::print(int i)
{
	std::cout << tabs(i) << "(Pipe)" << std::endl;
	for(auto s: sentences)
		s->print(i+1);
}

void ProgramNode::print(int i)
{
	std::cout << tabs(i) << "(Program)" << std::endl;
	for(auto c: codeNodes)
		c->print(i+1);
}

void FunctionDefNode::print(int i)
{
	std::cout << tabs(i) << "(Function) " << name  << std::endl;
	body->print(i+1);
}

void IfStatementNode::print(int i)
{
	std::cout << tabs(i) << "(IfStatement)" << std::endl;
	for(int j=0; j<condCodeNodes.size(); j++)
	{
		auto c = condCodeNodes[j];
		c->print(i+1);
	}
	std::cout << tabs(i) << "(Else)" << std::endl;
	elseNode->print(i+1);
}

void WhileLoopNode::print(int i)
{
	std::cout << tabs(i) << "(WhileLoop)" << std::endl;
	condition->print(i+1);
	body->print(i+1);
}
