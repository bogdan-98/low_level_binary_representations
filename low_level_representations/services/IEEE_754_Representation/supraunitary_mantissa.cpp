#include "SupraUnitaryMantissa.h"

int SubUnitaryNumberSupraUnitMantissaIEEE754::CalculateExponent(double number) {
    if (number <= 0 || number >= 1) {
        throw std::invalid_argument("Number must be in the range (0, 1)");
    }

    int resultOp = 0;
    double numberInUse = number;

    while (numberInUse < 1) {
        resultOp++;
        numberInUse *= 2;
    }

    return resultOp;
}

std::string SubUnitaryNumberSupraUnitMantissaIEEE754::CalculateMantissa(double number) {
    std::string mantissaBinary;

    for (int i = 0; i < 23; ++i) { // IEEE 754 single precision has 23 bits for mantissa
        number *= 2;
        if (number >= 1) {
            mantissaBinary.push_back('1');
            number -= 1; // Remove the leading 1
        } else {
            mantissaBinary.push_back('0');
        }
    }

    return mantissaBinary;
}

std::size_t SupraUnitaryNumberSupraUnitMantissaIEEE754::CalculateExponent(double number) {
    if (number <= 1) {
        throw std::invalid_argument("Number must be greater than 1.");
    }

    // Extract the integer part of the number
    int integerPart = static_cast < int > (number);
    std::string binaryRepresentation;

    // Convert the integer part to binary
    while (integerPart > 0) {
        binaryRepresentation.push_back(static_cast < char > ('0' + (integerPart % 2)));
        integerPart /= 2;
    }
    std::ranges::reverse(binaryRepresentation);

    // Find the position of the first '1' from the right (starting from the end)
    const std::size_t firstOnePos = binaryRepresentation.find_first_of('1') + 1;

    // Compute the length from the first '1' to the end
    const std::size_t lengthFromFirstOne = binaryRepresentation.size() - firstOnePos;

    // Calculate the exponent by adding the bias (127)
    return 127 + lengthFromFirstOne;
}

std::string SupraUnitaryNumberSupraUnitMantissaIEEE754::CalculateMantissa(double number) {
    if (number <= 1) {
        throw std::invalid_argument("Number must be greater than 1.");
    }

    // Extract integer part and convert to binary
    const int integerPart = static_cast < int > (number);
    double fractionalPart = number - integerPart;
    std::string mantissaBinary = std::bitset < 23 > (integerPart).to_string();

    // Trim leading zeros in the integer part
    mantissaBinary.erase(0, mantissaBinary.find_first_not_of('0'));
    mantissaBinary = mantissaBinary.substr(1);

    // Add binary representation of the fractional part until mantissa is 23 bits
    while (mantissaBinary.size() < 23) {
        fractionalPart *= 2;
        if (fractionalPart >= 1) {
            mantissaBinary.push_back('1');
            fractionalPart -= 1;
        } else {
            mantissaBinary.push_back('0');
        }
    }

    // Ensure mantissa is exactly 23 bits
    if (mantissaBinary.size() > 23) {
        mantissaBinary = mantissaBinary.substr(0, 23);
    }

    return mantissaBinary;
}