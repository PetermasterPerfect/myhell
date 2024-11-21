#include "Ast.h"

// we can assume word has closing quote because it's checked during building ast
bool isWordQuoted(std::string str)
{
	if(str[0] == '"' || str[0] == '\'')
		return true;
	return false;
}

//TODO: xxx"sdadsa'sdsad'dadsa"dsads\'"\'
std::string processedWords(std::vector<std::string> words, HadesExecutor& exec)
{
	std::string processedWord;
	for(auto w: words)
	{
		if(w[0] == '$')
		{
			std::string key = w.substr(1, w.size());
			if(auto value = exec.variables.find(key); value != exec.variables.end())
				processedWord += value->second;
		}
		else
		{

			bool escaped = false;
			if(isWordQuoted(w))
				for(auto it=w.begin()+1; it!=w.end()-1; it++)
				{
					if(escaped)
					{
						escaped = false;
						if(*it == '\\' || *it == '$' )
							processedWord+=*it;
						else
							processedWord+=std::string('\\', *it);
					}
					else if(*it == '\\')
						escaped = true;
					else
						processedWord+=*it;
				}
			else
				for(auto it=w.begin(); it!=w.end(); it++)
				{
					if(escaped)
					{
						escaped = false;
						processedWord+=*it;
					}
					else if(*it == '\\')
						escaped = true;
					else
						processedWord+=*it;
				}
		}

	}

	return processedWord;
}

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
	std::cout << tabs(i) << "(Assignment) varname=" << varName << "\n";
	for(auto v: value)
		v->print(i+1);
}

void WordsNode::print(int i)
{
	std::cout << tabs(i) << "(Words) ";
	if(fileOp == TOFILE)
		std::cout << "TOFILE>";
	else if(fileOp == FROMFILE)
		std::cout << "FROMFILE<";

	for(auto w: words)
		std::cout << tabs(i) <<  w << std::endl;
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

// ----------------------------------

void SentenceNode::execute(HadesExecutor& exec)
{
	std::vector<std::string> cmd;
	std::string out;
	std::string in;
	for(auto atom: atomNodes)
	{
		if(std::dynamic_pointer_cast<AssignmentNode>(atom))
			atom->execute(exec);
		else
		{
			std::shared_ptr<WordsNode> w = std::dynamic_pointer_cast<WordsNode>(atom);
			if(w->fileOp == FROMFILE)
				in = processedWords(w->words, exec);
			else if(w->fileOp == TOFILE)
				out = processedWords(w->words, exec);
			else
				cmd.push_back(processedWords(w->words, exec));
		}
	}
	std::cout << "CMD: ";
	for(auto c: cmd)
		std::cout << c << " ";
	std::cout << "\nIN: " << out << std::endl;
	std::cout << "OUT: " << in << std::endl;
}

void AssignmentNode::execute(HadesExecutor& exec)
{
	//exec.variables[varName] = processedWords(value, exec);
}

void WordsNode::execute(HadesExecutor& exec)
{
}

void PipeNode::execute(HadesExecutor& exec)
{
	for(auto s: sentences)
		s->execute(exec);
}

void ProgramNode::execute(HadesExecutor& exec)
{
	for(auto it=codeNodes.begin(); it!=codeNodes.end();)
	{
		if(std::dynamic_pointer_cast<FunctionDefNode>(*it))
		{
			exec.functions[std::dynamic_pointer_cast<FunctionDefNode>(*it)->name] = std::dynamic_pointer_cast<FunctionDefNode>(*it)->body;
			it = codeNodes.erase(it);
		}
		else
		{
			(*it)->execute(exec);
			it++;
		}
	}
}

void FunctionDefNode::execute(HadesExecutor& exec)
{
	exec.functions[name] = body;
}

void IfStatementNode::execute(HadesExecutor& exec)
{
	for(auto c: condCodeNodes)
		c->execute(exec);
	elseNode->execute(exec);
}

void WhileLoopNode::execute(HadesExecutor& exec)
{
	condition->execute(exec);
	body->execute(exec);
}
