#ifndef natural
#define natural

#include <vector>
#include <string>

class Natural {
    public:
        std::vector<int> number;
        Natural(std::string constant);
        std::string to_string();
        Natural operator +(Natural other);
        Natural operator -(Natural other);
};

#endif