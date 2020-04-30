#ifndef errors
#define errors

#include <string>
#include "asp.hpp"

void syntax_error(std::string message);
void symbol_undefined(std::string symbol);
void invalid_ast(AbstractSyntaxTree &code);

#endif