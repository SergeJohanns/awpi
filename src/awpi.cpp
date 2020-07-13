#include <string.h>
#include <iostream>
#include "constants.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // No arguments given
        std::cout << "No source file given." << std::endl;
        return ERROR_STATUS;
    } else {
        // Run file
        display_state(exec(lex(parse(argv[0], argv[1]))));
    }
}
