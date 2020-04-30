#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "parser.hpp"
#include "constants.hpp"

std::string root;

/**
 * Read a source code file, eliminate unnecessary whitespace, and resolve imports.
 */
std::string read_source(std::string filename) {
    std::ifstream source_file;
    bool found = false;
    if (filename.substr(0, STD_PREFIX.length()) == STD_PREFIX) {
        source_file.open(root + filename.substr(STD_PREFIX.length()));
    } else {
        source_file.open(filename);
    }
    if (source_file.is_open()) {
        std::string out = "";
        std::string line;
        while (getline(source_file, line)) {
            // Replace all tabs by a single space, so they can also be cleaned up.
            line = std::regex_replace(line, std::regex("\t"), " ");
            if (line.substr(0, IMPORT.length()) == IMPORT) {
                // Read the imported file and insert it. The regex serves to remove leading and trailing spaces from the filename.
                out += read_source(std::regex_replace(line.substr(IMPORT.length()), std::regex("^ +| +$"), ""));
            } else {
                // Insert the line. The regex removes all leading and trailing spaces, and collapses adjacent spaces into one.
                out += std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1") + " ";
            }
        }
        source_file.close();
        return out;
    } else {
        std::cout << "Could not import source file " + filename << std::endl;
        exit(ERROR_STATUS);
    }
}

/**
 * Set the root directory of the program to locate resources.
 */
void init_root(std::string bindir) {
    root = bindir;
    for (int i = 0; i < BIN_DEPTH; i++) {
        root = root.substr(0, root.find_last_of("/"));
    }
    root += PRELUDE;
}

/**
 * Parse the source code of a given file.
 */
std::string run(char* root, char* filename) {
    init_root(std::string(root));
    return read_source(std::string(filename));
}