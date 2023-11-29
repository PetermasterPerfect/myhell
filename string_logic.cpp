#include "string_logic.h"
#include <iostream>

void main_shell_loop()
{

	while(1)
	{
		std::string s = get_single_command();

	}
}


#define DEBUG_QTYPE(q) std::cout << #q << " " << q << "\n";
std::string get_single_command()
{
	std::string complete_line;
	unclosed_type new_qtype = none_quote;
	bool first = true;
	do
	{
		std::string line;
		if(first)
		{
			std::cout << "$ ";
			first = false;
		}
		else
		{
			new_qtype = new_qtype == pipe_sym || new_qtype == slash
				? none_quote: new_qtype;
			std::cout << "> ";
		}
		std::getline(std::cin, line);

		new_qtype = determine_unclosed_quote(line, new_qtype);
		DEBUG_QTYPE(new_qtype);	
		complete_line += line + "\n";
	}while(new_qtype != none_quote);
	return complete_line;
}

std::vector<std::string> split_cmd(std::string cmd)
{

}


unclosed_type determine_unclosed_quote(std::string line, unclosed_type old) 
{
	unclosed_type info = old;
	bool pipe = false;
	bool old_closed = old ? false: true;
	bool slashed = false;
	for(char &c: line)
	{
		if(slashed)
		{
			slashed = false;
			continue;
		}

		if(is_char_quote(c))
		{
			
			if(c == (char)old)
				old_closed = true;

			if(info == none_quote)
				switch(c)	
				{
					case '"':
						info = double_quote;
						break;
					case '\'':
						info = single_quote;
						break;
					case '`':
						info = grave_accent;
						break;
				}
			else if(info == c)
				info = none_quote;	
		}
		else if(c == '|' && info == none_quote)
			pipe = true;
		else if(c == '\\')
			slashed = true;

	}
	trim_end(line); // <-- trim_end should return string so i'll be able to use it in if statement
	if(info == none_quote)
	{
		if((char)*(line.end()-1) == '|')
			info = pipe_sym;
		else if((char)*(line.end()-1) == '\\')
			info = slash;
	}
	return old_closed ? info: old;
}
