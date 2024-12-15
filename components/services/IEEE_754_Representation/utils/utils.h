#ifndef UTILIS_H
#define UTILIS_H

#include <string>

class utils {
public:
    static std::string DecimalIntegerToBinaryExponent(const std::size_t number);
    static bool checkIfPositive(const double number);
    static std::string checkValueRange(const double number);
    static std::string returnValue(double number, const std::string& mantissaType);
};

#endif //UTILIS_H
