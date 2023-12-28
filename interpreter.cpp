#include "interpreter.h"

void atomic_cmd::reset()
{
	argv.clear();
	redirect_in.clear();
	redirect_out.clear();
}

Interpreter::Interpreter()
{
	cwd = fs::current_path();
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
	//int *pipes[2] = new int[ordered_cmd.size()];
	std::vector<int[2]> cmd_pipes(ordered_cmd.size()-1);
	std::vector<pid_t> child(ordered_cmd.size());
	for(int i=0; i<cmd_pipes.size(); i++)
		if(pipe(cmd_pipes[i]) == -1)
		{
			fprintf(stderr, "pipe error\n");
			return;
		}

	for(size_t i=0; i<ordered_cmd.size(); i++)
	{
		auto cmd = &ordered_cmd[i];
		
		if(child[i]=fork() == -1)
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
					if(j != i)
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
				write_file = open(cmd->redirect_in.c_str(), O_WRONLY);
				dup2(write_file, 1);
			}
			else
				dup2(cmd_pipes[i][1], 1);

			const char *pathname = cmd->argv[0].c_str();
			const char **arguments = new const char*[cmd->argv.size()];
			if(arguments == nullptr)
			{
				fprintf(stderr, "no memory\n");
				return;
			}
			for(size_t it=1; it<cmd->argv.size(); it++)
				arguments[it] = cmd->argv[it].c_str();
			arguments[cmd->argv.size()-1] = 0;

			execve(pathname, (char* const*)arguments, NULL);
			fprintf(stderr, "execve failed\n");
			delete[] arguments;
		}
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

