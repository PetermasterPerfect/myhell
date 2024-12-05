#include "AstBuilder.h"
#include <iostream>

int main(int argc, char **argv)
{
	HadesExecutor exec;
	std::string fullCmdInput;		

	LexerErrorListener lexerErrListener;
	std::shared_ptr<AstBuilderErrorStrategy> handler = std::make_shared<AstBuilderErrorStrategy>();
	if(!handler)
		return -1;

	std::unique_ptr<AstBuilder> test;
	while(1)
	{
		try
		{
			std::string cmdInput;
			if(fullCmdInput.empty())
				std::cout << "$ ";
			else
			{
				std::cout << "> ";
				fullCmdInput += '\n';
			}
			std::getline(std::cin, cmdInput);
			fullCmdInput += cmdInput;
			//std::cout << "full: " << fullCmd << "\n";
			//std::ifstream f("../test1.had");
			//ANTLRInputStream input(f);
			ANTLRInputStream input(fullCmdInput);
			HadesLexer lexer(&input);
			lexer.removeErrorListeners();
			lexer.addErrorListener(&lexerErrListener);
			CommonTokenStream tokens(&lexer);
			HadesParser parser(&tokens);
			parser.setErrorHandler(handler);
			
			ParseTree *tree = parser.program();
			test = std::make_unique<AstBuilder>(tokens);
			test->visit(tree);
			test->printAst();
			test->getAstTree()->execute(exec);
			fullCmdInput.erase();
		}
		catch(SyntaxError const &e)
		{
			std::cerr << e.what() << std::endl;
			fullCmdInput.erase();
		}
		catch(std::exception const &e)
		{
		}


		
	}
}
