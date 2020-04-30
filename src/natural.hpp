#ifndef natural
#define natural

#include <vector>
#include <string>

class Natural {
    public:
        std::vector<int> number;
        Natural();
        Natural(std::string constant);
        static Natural zero();
        std::string to_string();
        Natural operator +(Natural other);
        Natural operator -(Natural other);
        bool operator ==(Natural other);
        bool operator !=(Natural other);
};

#endif