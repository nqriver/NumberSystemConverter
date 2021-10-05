#include <iostream>
#include "NumberConverter.h"

void convertMessage(int value, const NumberConverter &numberConverter) {
    std::cout << value << "(" << numberConverter.default_base << ")" << "--->"
              << numberConverter.getConvertedValue(value) << "(" << numberConverter.getNewBase() << ")\n";
}

int main() {
    NumberConverter converter(21);

    convertMessage(124, converter);

    converter.setNewBase(2);
    convertMessage(52, converter);
    return 0;
}
