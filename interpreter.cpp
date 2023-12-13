#include "interpreter.h"

Interpreter::Interpreter()
{
	cwd = fs::current_path();
}

void Interpreter::set_finish(int st, std::string in)
{
	finish.status = st;
	finish.info = in;
}

void Interpreter::order_arguments()
{

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
		execve(...);
		_exit(EXIT_FAILURE);   // exec never returns
	}
}

