#include <vector>
#include <string>
#include <filesystem>
#include "string_logic.h"

namespace fs = std::filesystem;

struct finish_status
{
	int status
	std::string info;
}

struct atom_cmd
{
	std::string argv;
	std::string redirect_in;
	std::string redirect_out;
}

class Interpreter
{
	fs::path cwd;
	std::vector<atomic_argument> org_cmd;
	std::vector<std::string> ordered_cmd;
	
	finish_status finish;
	
	Interpreter();
	~Interpreter();

	void order_arguments();
	void set_cmd(std::vector<std::string>);
	void run_process(std::string, std::vector<std::string>);
	void execute();

	void set_finish(int, std::string);
};
