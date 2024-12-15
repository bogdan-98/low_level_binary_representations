#include "SubUnitaryMantissa.h"

int SubUnitaryNumberSubUnitMantissaIEEE754::CalculateExponent(double number) {
    if (number <= 0 || number >= 1) {
        throw std::invalid_argument("Number must be in the range (0, 1)");
    }

    int resultOp = 0;
    double numberInUse = number;

    while (numberInUse * 2 < 1) {
        resultOp++;
        numberInUse *= 2;
    }

    return resultOp;
}

std::string SubUnitaryNumberSubUnitMantissaIEEE754::CalculateMantissa(double number) {
    std::string mantissaBinary;

    for (int i = 0; i < 23; ++i) {
        number *= 2;
        if (number >= 1) {
            mantissaBinary.push_back('1');
            number -= 1;
        } else {
            mantissaBinary.push_back('0');
        }
    }

    return mantissaBinary;
}

std::size_t SupraUnitaryNumberSubUnitaryMantissaIEEE754::CalculateExponent(double number) {
    if (number <= 1) {
        throw std::invalid_argument("Number must be greater than 1.");
    }

    int integerPart = static_cast<int>(number);
    std::string binaryRepresentation;

    while (integerPart > 0) {
        binaryRepresentation.push_back(static_cast<char>('0' + (integerPart % 2)));
        integerPart /= 2;
    }
    std::ranges::reverse(binaryRepresentation.begin(), binaryRepresentation.end());

    std::size_t shifts = binaryRepresentation.size();
    return 127 + shifts;
}

std::string SupraUnitaryNumberSubUnitaryMantissaIEEE754::CalculateMantissa(double number) {
    if (number <= 1) {
        throw std::invalid_argument("Number must be greater than 1.");
    }

    int integerPart = static_cast<int>(number);
    double fractionalPart = number - integerPart;
    std::string mantissaBinary = std::bitset<23>(integerPart).to_string();

    mantissaBinary.erase(0, mantissaBinary.find_first_not_of('0'));

    while (mantissaBinary.size() < 23) {
        fractionalPart *= 2;
        if (fractionalPart >= 1) {
            mantissaBinary.push_back('1');
            fractionalPart -= 1;
        } else {
            mantissaBinary.push_back('0');
        }
    }

    if (mantissaBinary.size() > 23) {
        mantissaBinary = mantissaBinary.substr(0, 23);
    }

    return mantissaBinary;
}