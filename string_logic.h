#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define QUOTES "\"'`\0"

enum unclosed_type
{
	none_quote, // special use
	double_quote = (int)'"', // "
	single_quote = (int)'\'', // '
	grave_accent = (int)'`',  // `
	pipe_sym = (int)'|',
	slash = '\\'
};

inline void trim_begin(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), 
				[](char c){ return !isspace(c);}));
}

inline void trim_end(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		[](char c){ return !isspace(c);}).base(), str.end());
}

inline void trim(std::string &str)
{
	// trim beginning
	trim_begin(str);
	// trim ending
	trim_end(str);
};

inline bool is_potentially_unclosed(std::string str)
{
	for(const char *c=QUOTES; c<=QUOTES+2; c++)
		if(str.find(*c) != std::string::npos)
			return true;
	return false;
}

inline bool is_quote(char ch)
{
	for(const char *c=QUOTES; c<=QUOTES+2; c++)
		if(*c == ch)
			return true;
	return false;
}

void main_shell_loop();
unclosed_type determine_unclosed_quote(std::string, unclosed_type);
std::string get_single_command();
std::vector<std::string> split_cmd(std::string);
