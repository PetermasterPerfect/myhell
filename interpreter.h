#include <vector>
#include <string>
#include <filesystem>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "string_logic.h"

namespace fs = std::filesystem;

struct finish_status
{
	int status;
	std::string info;
};

struct atomic_cmd
{
	std::vector<std::string> argv; // argv[0] - executable file path
	std::vector<std::string> redirect_in;
	std::string redirect_out;
	bool in, out;
	void reset();
};

class Interpreter
{
	fs::path cwd;
	std::vector<atomic_cmd> ordered_cmd;
	
	finish_status finish;
	

	void run_process(std::string, std::vector<std::string>);
	void execute();

	void set_finish_stat(int, std::string);

public:
	void print_ordered_cmd();
	void order_arguments(std::vector<atomic_argument*>);
	Interpreter();
};
