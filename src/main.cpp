#include "AstBuilder.h"
#include <iostream>
#include <locale>
#include <codecvt>
#include <sys/stat.h>


void setupLexingParsingAndRun(ANTLRInputStream&, HadesExecutor&);

int main(int argc, char **argv)
{
	HadesExecutor exec;
	std::string fullCmdInput;		
	std::locale::global(std::locale("C.utf8"));
	struct stat sb;

	if(argc >= 2)
	{
		if (stat(argv[1], &sb) == 0 && !(sb.st_mode & S_IXUSR)) 
		{
			std::cerr << argv[1] << ": Permission denied\n";
			return -1;
		}

		std::string scriptName = argv[1];
		std::vector<std::string> arguments;
		for(size_t i=2; i<argc; i++)
		{ 
			std::stringstream argi;
			argi << "arg" << i-1;
			exec.variables[argi.str()] = argv[i];
		}
		
		std::ifstream f(scriptName);
		if(f)
		{
			try
			{
				ANTLRInputStream input(f);
				setupLexingParsingAndRun(input, exec);

			}
			catch(SyntaxError const &e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch(std::exception const &e)
			{
				std::cerr << e.what() << std::endl;
			}

		}
		else
		{
			std::cerr << "Could not run the file\n";
			return -1;
		}

	}
	else
	{
		while(1)
		{
			try
			{
				std::string cmdInput;
				if(fullCmdInput.empty())
					std::wcout << L"\U0001F525 ";
				else
				{
					std::cout << "> ";
					fullCmdInput += '\n';
				}
				if(!std::getline(std::cin, cmdInput))
					break;
				fullCmdInput += cmdInput;
				ANTLRInputStream input(fullCmdInput);
				setupLexingParsingAndRun(input, exec);

				fullCmdInput.erase();
			}
			catch(SyntaxError const &e)
			{
				std::cerr << e.what() << std::endl;
				fullCmdInput.erase();
			}
			catch(std::exception const &e)
			{
				fullCmdInput.erase();
			}
		}
	}
}

void setupLexingParsingAndRun(ANTLRInputStream &input, HadesExecutor &exec)
{
	LexerErrorListener lexerErrListener;
	AstBuilderErrorListener errListener;
	std::shared_ptr<AstBuilderErrorStrategy> handler = std::make_shared<AstBuilderErrorStrategy>();
	if(!handler)
		throw std::runtime_error("Memory allocation failed");
	std::unique_ptr<AstBuilder> builder;

	HadesLexer lexer(&input);
	lexer.removeErrorListeners();
	lexer.addErrorListener(&lexerErrListener);
	CommonTokenStream tokens(&lexer);
	HadesParser parser(&tokens);
	parser.setErrorHandler(handler);
	parser.removeErrorListeners();
	parser.addErrorListener(&errListener);
	
	ParseTree *tree = parser.program();
	builder = std::make_unique<AstBuilder>(tokens);
	builder->visit(tree);
	builder->getAstTree()->execute(exec);
}
