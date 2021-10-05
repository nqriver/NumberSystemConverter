#include <vector>
#include <algorithm>
#include <numeric>
#include "NumberConverter.h"

NumberConverter::NumberConverter(int new_base) : new_base{ new_base }
{
}

void NumberConverter::setNewBase(int new_base) {
    this->new_base = new_base;
}

std::string NumberConverter::getConvertedValue(int value) const {
    return convertValue(value);
}

std::string NumberConverter::convertValue(int value) const {
    std::vector<int> tokens;
    while (value != 0) {
        tokens.push_back(value % new_base);
        value /= new_base;
    }
    std::reverse(tokens.begin(), tokens.end());

    std::string result = std::accumulate(std::next(tokens.begin()),
                                         tokens.end(),
                                         std::to_string(tokens[0]),
                                         [](std::string s, int i) { return std::move(s) + " " + std::to_string(i); }
                                         );

    return result;
}

int NumberConverter::getNewBase() const {
    return new_base;
}
