#include <vector>
#include <string>
#include <cstdlib>
#include "natural.hpp"
#include "constants.hpp"

Natural::Natural(std::string constant) {
    for (int i = constant.size() - 1; i >= 0; i++) {
        number.push_back(constant[i]);
    }
}

Natural Natural::operator+(Natural other) {
    auto out = Natural("0");
    add_vectors(out.number, this->number);
    add_vectors(out.number, other.number);
    return out;
}

Natural Natural::operator-(Natural other) {
    auto out = Natural("0");
    sub_vectors(out.number, this->number);
    sub_vectors(out.number, other.number);
    return out;
}

void add_vectors(std::vector<int> &a, std::vector<int> &b) {
    int offset = 0;
    for (auto n : b) {
        add_to_vectors(a, n, offset++);
    }
}

void sub_vectors(std::vector<int> &a, std::vector<int> &b) {
    int offset = 0;
    for (auto n : b) {
        sub_from_vectors(a, n, offset++);
    }
}

void add_to_vectors(std::vector<int> &vector, int scalar, int offset) {
    int i = offset;
    int rem = scalar;
    while (rem > 0 && i < vector.size()) {
        vector[i] += rem;
        if (vector[i] >= CONST_BASE) {
            auto divmod = std::div(vector[i], CONST_BASE);
            vector[i] = divmod.rem;
            rem = divmod.quot;
        }
    }
    if (rem > 0) {
        vector.push_back(rem);
    }
}

void sub_from_vectors(std::vector<int> &vector, int scalar, int offset) {
    int i = offset;
    int rem = -scalar;
    while (rem < 0 && i < vector.size()) {
        vector[i] += rem;
        if (vector[i] < 0) {
            auto divmod = std::div(vector[i], CONST_BASE);
            vector[i] = divmod.rem;
            rem = divmod.quot;
        }
    }
    if (rem < 0) {
        vector = std::vector({0});
    }
}