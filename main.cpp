#include "antlr4-runtime.h"
#include "HadesParser.h"
#include "HadesLexer.h"
#include "HadesParserBaseVisitor.h"
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

class TestVisitor : public HadesParserBaseVisitor
{

};


int main(int argc, char **argv)
{
	//while(1)
	{
		std::ifstream f("../test.had");
		ANTLRInputStream input(f);
		//ANTLRInputStream input(std::string("x=sada"));
		HadesLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		HadesParser parser(&tokens);
		
		ParseTree *tree = parser.program();
		TestVisitor test;
		test.visit(tree);
	}
}
