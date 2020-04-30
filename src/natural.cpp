#include <vector>
#include <string>
#include <cstdlib>
#include "natural.hpp"
#include "constants.hpp"

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
        vector = std::vector<int>({0});
    }
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

Natural::Natural() {

}

Natural::Natural(std::string constant) {
    for (int i = constant.size() - 1; i >= 0; i--) {
        number.push_back(constant[i]);
    }
}

Natural Natural::zero() {
    return Natural("0");
}

std::string Natural::to_string() {
    std::string out = "";
    for (int i = number.size(); i >= 0; i--) {
        out += number[i];
    }
    return out;
}

bool Natural::operator==(Natural other) {
    return this->number == other.number;
}

bool Natural::operator!=(Natural other) {
    return this->number != other.number;
}

Natural Natural::operator+(Natural other) {
    auto out = Natural::zero();
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
