#ifndef SUBUNITARY_MANTISSA_H
#define SUBUNITARY_MANTISSA_H

#include <string>
#include <stdexcept>
#include <bitset>
#include <cmath>
#include <algorithm>

class SubUnitaryNumberSubUnitMantissaIEEE754 {
public:
  static int CalculateExponent(double number);
  static std::string CalculateMantissa(double number);
};

class SupraUnitaryNumberSubUnitaryMantissaIEEE754 {
public:
  static std::size_t CalculateExponent(double number);
  static std::string CalculateMantissa(double number);
};

#endif // SUBUNITARY_MANTISSA_H
