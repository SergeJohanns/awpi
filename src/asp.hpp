#ifndef asp
#define asp

#include <string>
#include <vector>

class AbstractSyntaxTree {
    public:
        std::string token;
        std::vector<AbstractSyntaxTree> children;
        AbstractSyntaxTree(std::string token);
};

#endif