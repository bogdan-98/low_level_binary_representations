#include "console.h"
#include "../services/IEEE_754_Representation/utils/utils.h"

void console::representIEEE754FormatUI() {
    double number;
    std::cout << "Enter the number(double type): ";
    std::cin >> number;

    std::string mantissaType;
    std::cout << "Enter the mantissa type(SubUnitary|SupraUnitary): ";
    std::cin >> mantissaType;

    std::cout << "Transaction result: " << utils::returnValue(number, mantissaType) << "\n";
}

void console::performLowLevelArithmeticUI() {
    std::cout << "This feature is yet to be implemented.";
}

void console::printMenu() {
    std::cout << "Main Menu" << "\n";
    std::cout << "1. Represent a number in IEEE 754." << "\n";
    std::cout << "2. Perform low-level arithmetic operations." << "\n";
    std::cout << "3. Exit program." << "\n";
    std::cout << ">>>";
}

void console::run() {
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                console::representIEEE754FormatUI();
                break;
            case 2:
                console::performLowLevelArithmeticUI();
                break;
            case 3:
                std::cout << "Exiting...";
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again.";
                break;
        }
    }
}
