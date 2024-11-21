#include "AstBuilder.h"
#include <iostream>

int main(int argc, char **argv)
{
	HadesExecutor exec;
	while(1)
	{
		std::string cmd;
		std::getline(std::cin, cmd);
		//std::ifstream f("../test1.had");
		//ANTLRInputStream input(f);
		ANTLRInputStream input(cmd);
		HadesLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		HadesParser parser(&tokens);
		
		ParseTree *tree = parser.program();
		AstBuilder test(tokens);
		test.visit(tree);
		test.printAst();
		test.getAstTree()->execute(exec);
		
	}
}
