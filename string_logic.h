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
	pipe_sym = (int)'|'
};

inline void trim_end(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), 
		[](char c){ return !isspace(c);}).base(), str.end());
}

inline void trim(std::string &str)
{
	// trim beginning
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), 
				[](char c){ return !isspace(c);}));
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

inline bool is_char_quote(char ch)
{
	for(const char *c=QUOTES; c<=QUOTES+2; c++)
		if(*c == ch)
			return true;
	return false;
}


//class CommandLine
//{
//	std::array<char, 3> quotes{{'"', '\'', '`'}};
	void parse_unfinished_pipe();
	//std::pair<unclosed_type, bool> determine_unclosed_quote(std::string, unclosed_type);
	unclosed_type determine_unclosed_quote(std::string, unclosed_type);
	void parse();
	std::string parse_unclosed_quote(unclosed_type);
//}
