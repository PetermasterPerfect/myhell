#include "string_logic.h"
#include <iostream>

void parse()
{
	std::string complete_cmd;
	bool unclosed = false;
	unclosed_type desired_closing; 
		// only special cases that this shell handles are unclosed quotes 
		// and unfinished pipes
	std::string line;
	std::getline(std::cin, line);
	trim(line);
	if(line[line.size()-1] == '\n')
	{
		//parse_unfinished_pipe();
		unclosed = true;
	}
	else
	{
		//desired_closing = determine_unclosed_quote(line, none_quote);
		if(desired_closing != none_quote)
			unclosed = true;
	}
}
#define DEBUG_QTYPE(q) std::cout << #q << " " << q << "\n";
:wa
std::string parse_unclosed_quote(unclosed_type qtype)
{
	std::string complete_line;
	unclosed_type new_qtype = none_quote;
	do
	{
		std::string line;
		std::cout << ">";
		std::getline(std::cin, line);
		trim_end(line);

		new_qtype = determine_unclosed_quote(line, new_qtype);
		DEBUG_QTYPE(new_qtype);	
		complete_line += line + "\n";
	}while(new_qtype != none_quote); 
	return complete_line;
}

unclosed_type determine_unclosed_quote(std::string line, unclosed_type old) 
{
	unclosed_type info = old;
	bool pipe = false;
	bool old_closed = old ? false: true;
	for(char &c: line)
	{
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
	}
	if(info == none_quote && (char)(*(line.end()-1)) == '|')
		info = pipe_sym;	
	return old_closed ? info: old;
}


