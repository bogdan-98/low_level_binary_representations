#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include "services/SubUnitaryMantissa.h"
#include "services/SupraUnitaryMantissa.h"

// Converts a decimal integer to an 8-bit binary string
std::string DecimalIntegerToBinaryExponent(const std::size_t number) {
  std::size_t workNumber = number;
  std::string binaryResult;

  while (workNumber != 0) {
    binaryResult.push_back(static_cast < char > ('0' + (workNumber % 2)));
    workNumber /= 2;
  }

  std::ranges::reverse(binaryResult);

  while (binaryResult.size() < 8) {
    binaryResult.insert(binaryResult.begin(), '0');
  }

  return binaryResult;
}

// Checks if a number is positive
bool checkIfPositive(const double number) {
  return number > 0;
}

// Classifies a number into "SubUnitary", "EquiUnitary", or "SupraUnitary"
std::string checkValueRange(const double number) {
  if (number >= 0 && number < 1) {
    return "SubUnitary";
  } else if (number == 1) {
    return "EquiUnitary";
  } else if (number > 1) {
    return "SupraUnitary";
  } else {
    return "Out of range";
  }
}

int main() {
  double number;
  std::cout << "Insert a number: ";
  std::cin >> number;

  std::string mantissaType;
  std::cout << "Specify mantissa type (SubUnitary/SupraUnitary): ";
  std::cin >> mantissaType;

  std::string result;
  if (checkIfPositive(number)) {
    // Put the bit 0 as the number is positive.
    const std::string signDigit = std::to_string(0);
    result.append(signDigit);
  } else {
    // Put the bit 1 as the number is negative.
    const std::string signDigit = std::to_string(1);
    result.append(signDigit);
    number = std::abs(number);
  }

  const std::string numberStatus = checkValueRange(number); // Get control status based on the value range

  if (mantissaType == "SubUnitary") {
    // Handle based on the number's category (subunitary, supraunitary, or equiunitary)
    if (numberStatus == "SubUnitary") {
      // Subunitary case: normalize the number to the [1, 2) range
      int subunitaryExponentShift = SubUnitaryNumberSubUnitMantissaIEEE754::CalculateExponent(number);
      number *= std::pow(2, subunitaryExponentShift); // Normalize the number

      // Compute the exponent for subunitary numbers
      const int exponentInteger = 127 - subunitaryExponentShift;
      const std::string exponentString = DecimalIntegerToBinaryExponent(exponentInteger);
      result.append(exponentString);

      // Calculate the mantissa for the normalized number
      const std::string mantissaString = SubUnitaryNumberSubUnitMantissaIEEE754::CalculateMantissa(number);
      result.append(mantissaString);

    } else if (numberStatus == "SupraUnitary") {
      // Compute the exponent for subunitary numbers
      const std::size_t exponentInteger = SupraUnitaryNumberSubUnitaryMantissaIEEE754::CalculateExponent(number);
      const std::string exponentString = DecimalIntegerToBinaryExponent(exponentInteger);
      result.append(exponentString);

      // Calculate the mantissa for the normalized number
      const std::string mantissaString = SupraUnitaryNumberSubUnitaryMantissaIEEE754::CalculateMantissa(number);
      result.append(mantissaString);
    }
  } else {
    if (numberStatus == "SubUnitary") {
      // Subunitary case: normalize the number to the [1, 2) range
      int subunitaryExponentShift = SubUnitaryNumberSupraUnitMantissaIEEE754::CalculateExponent(number);
      number *= std::pow(2, subunitaryExponentShift); // Normalize the number
      number -= 1;

      // Compute the exponent for subunitary numbers
      const int exponentInteger = 127 - subunitaryExponentShift;
      const std::string exponentString = DecimalIntegerToBinaryExponent(exponentInteger);
      result.append(exponentString);

      // Calculate the mantissa for the normalized number
      const std::string mantissaString = SubUnitaryNumberSupraUnitMantissaIEEE754::CalculateMantissa(number);
      result.append(mantissaString);

    } else if (numberStatus == "SupraUnitary") {
      // Compute the exponent for subunitary numbers
      const std::size_t exponentInteger = SupraUnitaryNumberSupraUnitMantissaIEEE754::CalculateExponent(number);
      const std::string exponentString = DecimalIntegerToBinaryExponent(exponentInteger);
      result.append(exponentString);

      // Calculate the mantissa for the normalized number
      const std::string mantissaString = SupraUnitaryNumberSupraUnitMantissaIEEE754::CalculateMantissa(number);
      result.append(mantissaString);
    }
  }

  std::cout << result << std::endl;

}