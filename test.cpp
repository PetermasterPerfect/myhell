#include "string_logic.h"
#include <iostream>

int main()
{

	while(1)
	{
		std::string s = get_single_command();
		//std::cout << "----------" << std::endl;
		//std::cout << s;
		//std::cout << "----------\n" << std::endl;
		auto v = split_cmd(s);
		std::cout << "v.size " << v.size() << "\n";
		for(int i=0; i<v.size(); i++)
			std::cout << "i=" << i << " " << v[i] << "\n";
	}
}
