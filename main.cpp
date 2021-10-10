#include <iostream>
#include <cmath>
#include <limits>
#include "NumberConverter.h"

void convertMessage(int value, const NumberConverter &numberConverter) {
    std::cout << value << "(" << numberConverter.primary_base << ")" << "--->"
              << numberConverter.getConvertedValueAsString(value) << "(" << numberConverter.getTargetBase() << ")\n";
}

template<typename T>
bool almost_equal(T x, T y, int reps) {
    T maxFab = std::max( std::fabs(x) , std::fabs(y) ) ;
    return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * maxFab * reps;
}

template<typename T>
bool almost_equal_2(T valA, T valB, double epsilon = 1e-8) {
    return (std::abs(valA - valB) <= (std::max(std::abs(valA), std::abs(valB)) * epsilon));
}

void testWhileLoop() {
    double number = 0;
    int count = 0;
    while (!almost_equal(number, 100., count)) {
        number += 0.01;
        ++count;
    }
    std::cout << count;
}

int main() {
    NumberConverter converter(21);

    convertMessage(124, converter);

    converter.setTargetBase(2);
    convertMessage(52, converter);

    testWhileLoop();

    return 0;
}
