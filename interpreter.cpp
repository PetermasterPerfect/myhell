#include "interpreter.h"

void atomic_cmd::reset()
{
	argv.clear();
	redirect_in.clear();
	redirect_out.clear();
}

Interpreter::Interpreter()
{
}

void Interpreter::set_finish_stat(int st, std::string in)
{
	finish.status = st;
	finish.info = in;
}

void Interpreter::order_arguments(std::vector<atomic_argument*> original_cmd)
{
	std::vector<atomic_cmd> finish;
	bool out = false;
	bool in = false;
	atomic_cmd buf;
	for(auto &i : original_cmd)
	{
		if(i->operand)
		{
			if(out)
			{
				buf.redirect_out = i->str;
				out = false;
			}
			else if(in)
			{
				buf.redirect_in = i->str;
				in = false;
			}
			else
				buf.argv.push_back(i->str);
		}
		else
		{
			switch(i->str.c_str()[0]) // when we deal with operator we're sure str is 1 byte long
			{
				case '>':
					out = true;
					buf.out = true;
					break;
				case '<':
					in = true;
					buf.in = true;
					break;
				case '|':
					finish.push_back(buf);
					buf.reset();
			}
		}
	}
	finish.push_back(buf);
	ordered_cmd = finish;
	//std::reverse(ordered_cmd.begin(), ordered_cmd.end());
}


void Interpreter::print_ordered_cmd()
{
	for(auto &s: ordered_cmd)
	{
		std::cout << "argv: ";
		for(auto &a: s.argv)
			std::cout << a << ", ";

		std::cout << "\nin: ";
		std::cout << s.redirect_in;

		std::cout << "\nout: ";
		std::cout << s.redirect_out << "\n\n";
	}
}

void Interpreter::run_cmd()
{
	atomic_cmd *master = nullptr;
	atomic_cmd *slave = nullptr;
	std::vector<int*> cmd_pipes; // TODO: free cmd_pipes or replace new operator
	std::vector<pid_t> child;
	if(ordered_cmd.size() <= 1)
	{
		cmd_pipes.resize(1);
		cmd_pipes[0] = new int[2];
	}
	else
	{
		cmd_pipes.resize(ordered_cmd.size()-1);
		for(int i=0; i<cmd_pipes.size(); i++)
			cmd_pipes[i] = new int[2];
	}
	for(int i=0; i<cmd_pipes.size(); i++)
		if(pipe(cmd_pipes[i]) == -1)
		{
			fprintf(stderr, "pipe error\n");
			return;
		}

	for(size_t i=0; i<ordered_cmd.size(); i++)
	{
		auto cmd = &ordered_cmd[i];
		child.push_back(fork());	
		if(child[i] == -1)
		{
			fprintf(stderr, "pipe error\n");
			return;
		}

		if(child[i] == 0)
		{
			int read_file, write_file;
			if(i == 0)
			{
				close(cmd_pipes[0][0]);
				for(int j=1; j<cmd_pipes.size(); j++)
				{
					close(cmd_pipes[j][0]);
					close(cmd_pipes[j][1]);
				}
			}
			else
			{
				for(int j=0; j<cmd_pipes.size(); j++)
				{
					close(cmd_pipes[j][1]);
					if(j-1 == i)
						close(cmd_pipes[j][0]);
				}
			}

			if(cmd->in)
			{
				if(cmd->redirect_in.empty())
				{
					fprintf(stderr, "not input file\n");
					return;
				}
				read_file = open(cmd->redirect_in.c_str(), O_RDONLY);
				dup2(read_file, 0);
			}
			else if(i)
				dup2(cmd_pipes[i-1][0], 0); 

			if(cmd->out)
			{
				if(cmd->redirect_out.empty())
				{
					fprintf(stderr, "not output file\n");
					return;
				}
				write_file = open(cmd->redirect_out.c_str(), O_WRONLY|O_CREAT, 0644);
				if(write_file == -1)
					fprintf(stderr, "open failed: %s\n", strerror(errno));
				dup2(write_file, 1);
			}
			//else
			//	dup2(cmd_pipes[i][1], 1);

			const char *pathname = cmd->argv[0].c_str();
			const char **arguments = new const char*[cmd->argv.size()];
			if(arguments == nullptr)
			{
				fprintf(stderr, "no memory\n");
				return;
			}
			for(size_t it=0; it<cmd->argv.size(); it++)
				arguments[it] = cmd->argv[it].c_str();
			//arguments[cmd->argv.size()] = 0;

			if(std::find(builtin_cmd.begin(), builtin_cmd.end(), cmd->argv[0]) != builtin_cmd.end())
				run_builtin_cmd(cmd);
			else
			{
				execve(pathname, (char* const*)arguments, NULL);
				fprintf(stderr, "execve failed: %s\n", strerror(errno));
			}
			delete[] arguments;
		}
		else
			puts("parent proc!!!");
	}

	//for(int j=0; j<cmd_pipes.size(); j++)
	for(auto& pipe: cmd_pipes)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
	for(auto& c: child)
		waitpid(c, NULL, 0); 
}


void Interpreter::run_builtin_cmd(atomic_cmd *cmd)
{
	auto &arg = cmd->argv;
	if(arg[0] == "ls")
	{
		std::string dir;
		if(arg.size() == 1)
			dir = "./";
		else
			dir = arg[1];
		run_ls(dir);
	}
	else if(arg[0] == "cd")
	{
		if(arg.size() == 1)
		{
			std::cerr << "cd expectes 1 argument\n";
			return;
		}
		else if(arg.size() > 2)
		{
			std::cerr << "cd expectes 1 argument, too many arguments given\n";
			return;
		}
		//run_cd(arg[1]);
	}
}
void Interpreter::print_errno_info()
{
	switch(errno)
	{
		case EPERM:
			std::cerr << "Operation not permitted\n";
			break;
		case ENOENT:
			std::cerr << "No such file or directory\n";
			break;
	}
}
void Interpreter::run_ls(std::string dir_path)
{
	DIR *dir = opendir(dir_path.c_str());
	dirent *entry;

	if(dir == NULL)
	{
		print_errno_info();
		exit(errno);
	}

    while ((entry = readdir(dir)) != NULL)
		std::cout << entry->d_name << "\n";
    
    closedir(dir);
	exit(0);
}

