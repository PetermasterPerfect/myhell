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
	atomic_cmd buf;
	auto ref = &buf.argv;
	for(auto &i : original_cmd)
	{
		if(i->operand)
		{
			if(out)
			{
				buf.redirect_out = i->str;
				out = false;
			}
			else
				ref->push_back(i->str);
		}
		else
		{
			switch(i->str.c_str()[0]) // when we deal with operator we're sure str is 1 byte long
			{
				case '>':
					out = true;
					break;
				case '<':
					ref = &buf.redirect_in;
					break;
				case '|':
					finish.push_back(buf);
					buf.reset();
					ref = &buf.argv;
			}
		}
	}
	finish.push_back(buf);
	ordered_cmd = finish;
}


void Interpreter::print_ordered_cmd()
{
	for(auto &s: ordered_cmd)
	{
		std::cout << "argv: ";
		for(auto &a: s.argv)
			std::cout << a << ", ";

		std::cout << "\nin: ";
		for(auto &i: s.redirect_in)
			std::cout << i << ", ";

		std::cout << "\nout: ";
		std::cout << s.redirect_out << "\n";
	}
}

void Interpreter::run_process(std::string path, std::vector<std::string> arg)
{
	pid_t parent = getpid();
	pid_t pid = fork();

	if (pid == -1)
	{
		// error, failed to fork()
	} 
	else if (pid > 0)
	{
		int status;
		waitpid(pid, &status, 0);
	}
	else 
	{
		// we are the child
		//execve(...);
		_exit(EXIT_FAILURE);   // exec never returns
	}
}

