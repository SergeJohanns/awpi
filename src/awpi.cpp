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
    } else if (argv[1] == "-g") {
        // Compute Godelization
        if (argc < 3) {
            std::cout << "No source file given." << std::endl;
            return ERROR_STATUS;
        }
        std::cout << "Not yet implemented" << std::endl;
        //lex(run(argv[0], argv[2]));
    } else if (argv[1] == "-G") {
        // Compute Godel number
        if (argc < 3) {
            std::cout << "No source file given." << std::endl;
            return ERROR_STATUS;
        }
        std::cout << "Not yet implemented" << std::endl;
        //lex(run(argv[0], argv[2]));
    } else {
        // Run file
        display_state(exec(lex(parse(argv[0], argv[1]))));
    }
}
