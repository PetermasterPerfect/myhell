#include "Ast.h"
#include "ArithmeticEval.h"

// we can assume word has closing quote because it's checked during building ast
bool isWordQuoted(std::string str)
{
	if(str[0] == '"' || str[0] == '\'')
		return true;
	return false;
}

bool isWordForArithmetic(std::string str)
{
	if(str[0] == '`')
		return true;
	return false;
}

std::string processedWords(std::vector<std::string> words, HadesExecutor& exec)
{
	std::string processedWord;
	for(auto w: words)
	{
		if(w[0] == '$')
		{
			std::string key = w.substr(1);
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
			else if(isWordForArithmetic(w) && w.size() > 2)
			{
				ANTLRInputStream input(w.substr(1, w.size()-2));
				ArithmeticLexer lexer(&input);
				CommonTokenStream tokens(&lexer);
				ArithmeticParser parser(&tokens);
				ArithmeticErrorListener errListener;
				parser.removeErrorListeners();
				parser.addErrorListener(&errListener);
				
				ParseTree *tree = parser.expr();
				ArithmeticEval eval(exec);
				try
				{
					processedWord += std::to_string(std::any_cast<int>(eval.visit(tree)));
				}
				catch(...)
				{
					throw SyntaxError("Unexpected keyword in arithmetic operation");
				}
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
	std::cout << tabs(i) << "(SentenceNode) " << content.size() << std::endl;

	for(auto c: content)
	{
		c->print(i+1);
	}
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
		std::cout << tabs(i) << "(CONDCODE)" << std::endl;
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


void SentenceNode::execute(HadesExecutor& exec)
{
	std::vector<CommandForExecution> commands;
	std::string out;
	std::string in;

	for(auto c: content)
	{
		if(std::shared_ptr<SentenceNode> s = std::dynamic_pointer_cast<SentenceNode>(c))
		{
			exec.presentExecCmd.push_back(std::make_unique<CommandForExecution>());
			s->execute(exec);
		}
		else if(std::shared_ptr<AssignmentNode> ass = std::dynamic_pointer_cast<AssignmentNode>(c))
		{
			std::vector<std::string> assignmentValue;
			std::unique_ptr<CommandForExecution> cmd = std::make_unique<CommandForExecution>();
			if(!cmd)
				return;

			for(auto w: ass->value)
			{	
				if(w->fileOp == TOFILE)
					cmd->toFile = processedWords(w->words, exec);
				else if(w->fileOp != FROMFILE)
					assignmentValue.push_back(processedWords(w->words, exec));
			}

			exec.variables[ass->varName] = std::accumulate(assignmentValue.begin(), assignmentValue.end(), std::string(),
					[](const std::string &acc, const std::string &str)
					{
						return acc+str;
					});
			if(!exec.presentExecCmd.size())
				exec.presentExecCmd.push_back(std::make_unique<CommandForExecution>());
			exec.presentExecCmd.back()->supplementCommand(std::move(cmd));
		}
		else
		{
			std::unique_ptr<CommandForExecution> cmd = std::make_unique<CommandForExecution>();
			if(!cmd)
				return;
			std::shared_ptr<WordsNode> w = std::dynamic_pointer_cast<WordsNode>(c);
			std::string processed = processedWords(w->words, exec);;
			if(w->fileOp == FROMFILE)
				cmd->fromFile = processed;
			else if(w->fileOp == TOFILE)
				cmd->toFile = processed;
			else
				cmd->argv.push_back(processed);
			if(!exec.presentExecCmd.size())
				exec.presentExecCmd.push_back(std::make_unique<CommandForExecution>());
			exec.presentExecCmd.back()->supplementCommand(std::move(cmd));
		}
	}
}

void AssignmentNode::execute(HadesExecutor& exec)
{
}

void WordsNode::execute(HadesExecutor& exec)
{
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
			exec.presentExecCmd.clear();
			(*it)->execute(exec);
			exec.executeCommands();
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
	bool f = false;
	for(auto it=condCodeNodes.begin(); it!=condCodeNodes.end(); )
	{
		(*it)->execute(exec);
		if(!exec.lastStatus)
		{
			it++;
			(*it)->execute(exec);
			it++;
			f=true;
			break;
		}
		else
			it+=2;
	}
	if(!f)
		elseNode->execute(exec);
}


int WhileLoopNode::runConditionForStatus(HadesExecutor &exec)
{
	condition->execute(exec);
	return exec.lastStatus;
}

void WhileLoopNode::execute(HadesExecutor& exec)
{
	while(!runConditionForStatus(exec))
		body->execute(exec);
}

int HadesExecutor::executeCommands()
{
	std::vector<std::unique_ptr<int[]>> pipes;
	std::vector<pid_t> children;
	if(!presentExecCmd.size())
		return -1;

	if(presentExecCmd.size() > 1)
	{
		pipes.resize(presentExecCmd.size()-1);
		for(auto &p: pipes)
		{
			p = std::make_unique<int[]>(2);
			if(p[0])
				return -1;
		}
	}

	for(auto &p: pipes)
	{
		if(pipe(p.get()) == -1)
        {
            std::cerr << "pipe error\n";
            return -1;
        }
	}

	if(pipe(comPipes) == -1)
	{
		std::cerr << "pipe error\n";
		return -1;
	}

	for(size_t i=0; i<presentExecCmd.size(); i++)
	{
		auto &cmd = presentExecCmd[i];

		children.push_back(fork());
		if(children[i] == -1)
        {
            std::cerr << "fork error\n";
            return -1;
        }
		if(children[i] == 0)
		{
			int readFile, writeFile;
			if(presentExecCmd.size() > 1)
			{
				if(i == 0)
				{
					dup2(pipes[0][1], 1);
					for(size_t j=0; j<pipes.size(); j++)
					{
						close(pipes[j][0]);
						close(pipes[j][1]);
					}
				}
				else if(i == presentExecCmd.size()-1)
				{
					dup2(pipes[i-1][0], 0);
					for(size_t j=0; j<pipes.size(); j++)
					{
						close(pipes[j][0]);
						close(pipes[j][1]);
					}
				}
				else
				{
					dup2(pipes[i-1][0], 0);
					dup2(pipes[i][1], 1);

					for(size_t j=0; j<pipes.size(); j++)
					{
						close(pipes[j][0]);
						close(pipes[j][1]);
					}
				}
			}

			if(!cmd->fromFile.empty())
			{
				readFile = open(cmd->fromFile.c_str(), O_RDONLY);
				if(readFile == -1)
				{
					std::cerr << "error opening readFile\n";
					return -1;
				}
				dup2(readFile, 0);
			}

			if(!cmd->toFile.empty())
			{
				writeFile = open(cmd->toFile.c_str(), O_WRONLY|O_CREAT, 0644);
				if(writeFile == -1)
				{
					std::cerr << "error opening toFile\n";
					return -1;
				}
				dup2(writeFile, 1);
			}

			if(auto func = functions.find(cmd->argv[0]); func != functions.end())
			{

				pushArgumentsToScope(cmd->argv);

				func->second->execute(*this);

				exit(lastStatus);
			}
			if(std::find(builtinCmd.begin(), builtinCmd.end(), cmd->argv[0]) != builtinCmd.end())
				executeBuiltinCommandByChild(i);
			else
			{
				close(comPipes[0]);
				close(comPipes[1]);
			}

			const char *pathname = cmd->argv[0].c_str();
			const char** arguments = new const char*[cmd->argv.size()+1];
			if(!arguments)
				return -1;

			for(size_t j=0; j<cmd->argv.size(); j++)
				arguments[j] = cmd->argv[j].c_str();
			arguments[cmd->argv.size()] = 0;

			for(auto& s : basePaths)// simulating PATH variable
			{
				if(fileExistsInDir(s, cmd->argv[0]))
				{
					std::string temp = s+cmd->argv[0];
					pathname = temp.c_str();
					break;
				}
			}

			execve(pathname, (char* const*)arguments, NULL);
			std::stringstream err;
			err << strerror(errno) << "\n";
			
			delete[] arguments;
			arguments = new const char*[cmd->argv.size()+2];
			if(!arguments)
				return -1;


			arguments[0] = "myhell";
			for(size_t j=0; j<cmd->argv.size(); j++)
				arguments[j+1] = cmd->argv[j].c_str();
			arguments[cmd->argv.size()+1] = 0;

			execve("myhell", (char* const*)arguments, NULL);
			std::cerr << err.str();
			exit(-1);
		}
		else
		{
			if(std::find(builtinCmd.begin(), builtinCmd.end(), cmd->argv[0]) != builtinCmd.end())
			{
				char buf;
				if(read(comPipes[0], &buf, 1))
					executeBuiltinCommandByParent(i);
			}
			close(comPipes[0]);
			close(comPipes[1]);
		}
	}
    for(auto& pipe: pipes)
    {
        close(pipe[0]);
        close(pipe[1]);
    }
	
	int status;
	while(waitpid(children.back(), &status, 0) == -1);
	presentExecCmd.clear();
	lastStatus = status;
	return status;
}


void HadesExecutor::pushArgumentsToScope(std::vector<std::string> argv)
{
	std::unordered_map<std::string,std::string> arguments;
	for(size_t i=1; i<argv.size(); i++)
	{
		std::stringstream argi;
		argi << "arg" << i;
		arguments[argi.str()] = argv[i];
		variables[argi.str()] = argv[i];
	}
	argumentsScope.push(arguments);
}

void HadesExecutor::popArgumentsAndRestoreScope()
{
	auto top = argumentsScope.top();
	auto destScope = argumentsScope.top();
	if(destScope.size() < top.size())
		for(size_t i=destScope.size(); i<top.size(); i++)
		{
			std::stringstream argi;
			argi << "arg" << i;
			variables.erase(variables.find(argi.str()));
		}
	for(auto &p: destScope)
	{
		variables[p.first] = p.second;
	}

	argumentsScope.pop();
}

void HadesExecutor::executeBuiltinCommandByChild(size_t i)
{
	auto &cmd = presentExecCmd[i];
	if(cmd->argv[0] == "eval")
	{
		if(cmd->argv.size() == 0)
		{
			std::cerr << "Too few arguments for eval\n"; // TODO maybe throw
			lastStatus = -1;
		}
		else if(cmd->argv.size() > 2)
		{
			std::cerr << "Too much arguments for eval\n";
			lastStatus = -1;
		}
		else
		{
			int ret = stoi(cmd->argv[1]);
			lastStatus = ret == 1 ? 0: -1;
		}
	}
	else
	{
		close(comPipes[0]);
		write(comPipes[1], cmd->argv[0].c_str(), cmd->argv[0].size());
		close(comPipes[1]);
	}
	exit(lastStatus);
}

void HadesExecutor::executeBuiltinCommandByParent(size_t i)
{
	auto &cmd = presentExecCmd[i];
	if(cmd->argv[0] == "cd" )
	{
		if(cmd->argv.size() < 2)
			std::cerr << "No argument given\n";
		else if(cmd->argv.size() > 2)
			std::cerr << "To many arguments\n";
		else
		{
			if(chdir(cmd->argv[1].c_str()))
				std::cerr << "Bad directory given\n";
			else
				std::cout << "Directory changed\n";
		}
	}
	else if(cmd->argv[0] == "exit")
		exit(0);
}

bool HadesExecutor::fileExistsInDir(std::string dirPath, std::string file)
{
	DIR *dir = opendir(dirPath.c_str());
    dirent *entry;

    if(dir == NULL)
    	return false;

    while ((entry = readdir(dir)) != NULL)
    {
		if(file == entry->d_name)
		{
			closedir(dir);
			return true;
		}
    }
    
    closedir(dir);
	return false;
}
