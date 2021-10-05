#ifndef NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H
#define NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H


#include <string>

class NumberConverter {

private:
    int new_base;
public:
    int getNewBase() const;

    static constexpr int default_base { 10 };
private:

    std::string convertValue(int) const;

public:
    explicit NumberConverter(int);
    void setNewBase(int);

    std::string getConvertedValue(int value) const;





};


#endif //NUMBERSYSTEMCONVERTER_NUMBERCONVERTER_H
