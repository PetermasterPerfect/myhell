#include <vector>
#include <algorithm>
#include <string>
#include <filesystem>
#include <functional>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
//for debugging
#include <errno.h>
#include <string.h>
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
	std::string redirect_in;
	std::string redirect_out;
	bool in = false;
	bool out = false;
	void reset();
};

class Interpreter
{
	std::vector<atomic_cmd> present_cmd;
	std::array<std::string, 2> builtin_cmd{"ls", "cd"};
	finish_status finish;

	void set_finish_stat(int, std::string);

public:
	void run_cmd();
	void run_builtin_cmd(atomic_cmd*);
	void run_ls(std::string);
	void print_present_cmd();
	void print_errno_info();
	void order_arguments(std::vector<atomic_argument*>);
	Interpreter();
};
