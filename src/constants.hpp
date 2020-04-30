#ifndef constants
#define constants

#include <string>

const std::string DO = "do";
const std::string OD = "od";
const std::string CONS = "cons"; // Purely internal, does not affect syntax.
const std::string PLUS = "+";
const std::string MINUS = "-";
const std::string WHILE = "while";
const std::string ASSIGN = ":=";

const int ERROR_STATUS = 1;
const int BIN_DEPTH = 2;
const std::string STD_PREFIX = "prelude::";
const std::string IMPORT = "#import";
const std::string PRELUDE = "/prelude/";

#endif