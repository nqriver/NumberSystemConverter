#ifndef NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H
#define NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H


#include <string>

class NumberConverter {

private:
    int target_base;
    std::vector<int> convertValue(int) const;


public:
    static constexpr int primary_base { 10 };
    explicit NumberConverter(int);
    int getTargetBase() const;
    void setTargetBase(int);
    std::string getConvertedValueAsString(int) const;

};


#endif //NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H
