#pragma once
#include "Ast.h"
#include <unordered_map>

class HadesExecutor
{
public:
	std::unordered_map<std::string, std::string> variables;
	std::unordered_map<std::string,	std::shared_ptr<ProgramNode>> functions;

	HadesExecutor(){}
};
