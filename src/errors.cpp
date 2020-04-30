#include <string>
#include <iostream>
#include "errors.hpp"
#include "constants.hpp"

void syntax_error(std::string message) {
    std::cout << message << std::endl;
    exit(ERROR_STATUS);
}
