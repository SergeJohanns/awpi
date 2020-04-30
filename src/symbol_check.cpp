#include <regex>
#include "symbol_check.hpp"

bool is_constant(std::string symbol) {
    return std::regex_match(symbol, std::regex("0|[1-9][0-9]*"));
}

bool is_identifier(std::string symbol) {
    return std::regex_match(symbol, std::regex("[A-Za-z_']+"));
}