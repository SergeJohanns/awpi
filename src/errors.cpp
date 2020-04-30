#include <string>
#include <iostream>
#include "asp.hpp"
#include "errors.hpp"
#include "constants.hpp"

void syntax_error(std::string message) {
    std::cout << message << std::endl;
    exit(ERROR_STATUS);
}

void symbol_undefined(std::string symbol) {
    std::cout << "Encountered undefined identifier \"" + symbol + "\"" << std::endl;
    exit(ERROR_STATUS);
}

void invalid_ast(AbstractSyntaxTree &code) {
    std::cout << "Encountered unexpected syntax node \"" + code.token + "\"" << std::endl;
    exit(ERROR_STATUS);
}