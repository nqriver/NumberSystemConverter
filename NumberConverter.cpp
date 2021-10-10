#include <vector>
#include <algorithm>
#include <numeric>
#include "NumberConverter.h"

NumberConverter::NumberConverter(int target_base) : target_base{target_base }
{
}

void NumberConverter::setTargetBase(int newBase) {
    target_base = newBase;
}

std::string NumberConverter::getConvertedValueAsString(int value) const {
    auto tokens = convertValue(value);
    std::string textRepresentation = std::accumulate(std::next(tokens.begin()),
                                         tokens.end(),
                                         std::to_string(tokens[0]),
                                         [](std::string s, int i) { return std::move(s) + " " + std::to_string(i); }
                                         );
    return textRepresentation;
}

std::vector<int> NumberConverter::convertValue(int value) const {
    std::vector<int> tokens;
    while (value != 0) {
        tokens.push_back(value % target_base);
        value /= target_base;
    }
    std::reverse(tokens.begin(), tokens.end());
    return tokens;
    /// Copy elision and Named Return Value Optimization (NRVO)
}

int NumberConverter::getTargetBase() const {
    return target_base;
}
