#ifndef SUPRAUNITARYMANTISSA_H
#define SUPRAUNITARYMANTISSA_H

#include <string>
#include <stdexcept>
#include <bitset>
#include <cmath>
#include <algorithm>

class SubUnitaryNumberSupraUnitMantissaIEEE754 {
public:
    static int CalculateExponent(double number);
    static std::string CalculateMantissa(double number);
};

class SupraUnitaryNumberSupraUnitMantissaIEEE754 {
public:
    static std::size_t CalculateExponent(double number);
    static std::string CalculateMantissa(double number);
};

#endif //SUPRAUNITARYMANTISSA_H
