#include "interpreter.h"
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
		Interpreter interp;
		interp.order_arguments(v);
		interp.print_ordered_cmd();
		std::cout << "arguments len " << v.size() << "\n";
		interp.run_cmd();
		//for(int i=0; i<v.size(); i++)
		//	std::cout << "i=" << i << " " << v[i]->str << " , " << v[i]->operand << "\n";
		free_args(v);
	}
}
