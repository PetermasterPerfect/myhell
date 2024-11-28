#include "AstBuilder.h"
#include <iostream>

int main(int argc, char **argv)
{
	HadesExecutor exec;
	std::string fullCmd;		

	LexerErrorListener lexerErrListener;
	std::shared_ptr<AstBuilderErrorStrategy> handler = std::make_shared<AstBuilderErrorStrategy>();
	if(!handler)
		return -1;

	while(1)
	{
		try
		{
		std::string cmd;
		if(fullCmd.empty())
			std::cout << "$ ";
		else
		{
			std::cout << "> ";
			fullCmd += '\n';
		}
		std::getline(std::cin, cmd);
		fullCmd += cmd;
		//std::cout << "full: " << fullCmd << "\n";
		//std::ifstream f("../test1.had");
		//ANTLRInputStream input(f);
		ANTLRInputStream input(fullCmd);
		HadesLexer lexer(&input);
		lexer.removeErrorListeners();
		lexer.addErrorListener(&lexerErrListener);
		CommonTokenStream tokens(&lexer);
		HadesParser parser(&tokens);
		parser.setErrorHandler(handler);
		
		ParseTree *tree = parser.program();
		AstBuilder test(tokens);
		test.visit(tree);
		test.printAst();
		test.getAstTree()->execute(exec);
		fullCmd.erase();
		}
		catch(std::exception const &e)
		{
			std::cerr << "EXC: " << e.what() << "\n";
		}

		
	}
}
