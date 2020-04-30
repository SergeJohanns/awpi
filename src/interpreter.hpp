#ifndef header
#define header

#include <string>
#include <unordered_map>
#include "natural.hpp"
#include "asp.hpp"

typedef std::unordered_map<std::string, Natural> state;

state exec(AbstractSyntaxTree code);
void display_state(state prog);

#endif