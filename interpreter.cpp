#include "interpreter.h"

void atomic_cmd::reset()
{
	argv.clear();
	redirect_in.clear();
	redirect_out.clear();
	in = false;
	out = false;
}

Interpreter::Interpreter()
{
	
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
	present_cmd = finish;
}

void Interpreter::print_present_cmd()
{
	for(auto &s: present_cmd)
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
    std::vector<int*> pipes; // TODO: free pipes or replace new operator
    std::vector<pid_t> child;
    if(present_cmd.size() <= 1)
    {
        pipes.resize(1);
        pipes[0] = new int[2];
    }
    else
    {
        pipes.resize(present_cmd.size()-1);
        for(size_t i=0; i<pipes.size(); i++)
            pipes[i] = new int[2];
    }
    for(size_t i=0; i<pipes.size(); i++)
        if(pipe(pipes[i]) == -1)
        {
            std::cerr << "pipe error\n";
            return;
        }

    for(size_t i=0; i<present_cmd.size(); i++)
    {
        auto cmd = &present_cmd[i];
        child.push_back(fork());    
        if(child[i] == -1)
        {
            std::cerr << "fork error\n";
            return;
        }

        if(child[i] == 0)
        {
			//std::cout << "arg: " << cmd->argv[0] << std::endl;
            int read_file, write_file;
			if(present_cmd.size() > 1)
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
				else if(i == present_cmd.size()-1)
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
            if(cmd->in)
            {
                if(cmd->redirect_in.empty())
                {
                    std::cerr << "no input file\n";
                    return;
                }
                read_file = open(cmd->redirect_in.c_str(), O_RDONLY);
                dup2(read_file, 0);
            }

            if(cmd->out)
            {
                if(cmd->redirect_out.empty())
                {
                    std::cerr << "no output file\n";
                    return;
                }
                write_file = open(cmd->redirect_out.c_str(), O_WRONLY|O_CREAT, 0644);
                if(write_file == -1)
                    std::cerr << "open failed: " << strerror(errno) << "\n";
                dup2(write_file, 1);
            }

            const char *pathname = cmd->argv[0].c_str();
            const char **arguments = new const char*[cmd->argv.size()+1];
            if(arguments == nullptr)
            {
             	std::cerr << "no memory\n";
                return;
            }
            for(size_t k=0; k<cmd->argv.size(); k++)
                arguments[k] = cmd->argv[k].c_str();
            arguments[cmd->argv.size()] = 0;

			for(auto& s : path_base)// feature equivalent to PATH variable
			{
				if(search_for_file(s, cmd->argv[0]))
				{
					std::string temp = s+cmd->argv[0];
					pathname = temp.c_str();
				}
			}

            if(std::find(builtin_cmd.begin(), builtin_cmd.end(), cmd->argv[0]) != builtin_cmd.end())
				run_builtin_cmd(cmd);
			else
            {
                execve(pathname, (char* const*)arguments, NULL);
                std::cerr << "execve failed: " << strerror(errno) << "\n";
            }
            delete[] arguments;
        }

    }

    for(auto& pipe: pipes)
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
	if(arg[0] == "exit")
	{
		exit(0);
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
			std::cerr << "cd too many arguments \n";
			return;
		}
		run_cd(arg[1]);
	}
	//print_errno_info(); TODO: error printing
}
void Interpreter::print_errno_info()
{
	switch(errno)
	{

        case EACCES:
            std::cerr << "Search permission is denied for one of the components of path." << std::endl;
            break;
        case EFAULT:
            std::cerr << "path points outside your accessible address space." << std::endl;
            break;
        case EIO:
            std::cerr << "An I/O error occurred." << std::endl;
            break;
        case ELOOP:
            std::cerr << "Too many symbolic links were encountered in resolving path." << std::endl;
            break;
        case ENAMETOOLONG:
            std::cerr << "path is too long." << std::endl;
            break;
        case ENOENT:
            std::cerr << "The file does not exist." << std::endl;
            break;
        case ENOMEM:
            std::cerr << "Insufficient kernel memory was available." << std::endl;
            break;
        case ENOTDIR:
            std::cerr << "A component of path is not a directory." << std::endl;
            break;
        case EBADF:
            std::cerr << "fd is not a valid file descriptor." << std::endl;
            break;
        default:
            std::cerr << "Unknown error code: " << errno << std::endl;
            break;

	}
}

bool Interpreter::search_for_file(std::string dir_path, std::string file)
{
	DIR *dir = opendir(dir_path.c_str());
	dirent *entry;

	if(dir == NULL)
	{
		print_errno_info();
		exit(errno);
	}

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

void Interpreter::run_cd(std::string dir_path)
{
	chdir(dir_path.c_str());
}

