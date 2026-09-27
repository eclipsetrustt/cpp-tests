#include <iostream>
#include <string>

#include "idk.h"

void calculator() {
    while (true) {
        std::string value_parser, value2_parser; // lol copy n paste from the main.cpp
        std::cout << "\n1 - Plus operation\n2 - Minus operation\n3 - Multiply operation\n4 - Division operation\n0 - Quit\n";
        std::cin >> value_parser;

        auto option = tryParse(value_parser);
        if (option < 0 || option > 4) {
            std::cout << "Invalid option";
            continue;
        }

        if (option == 0) {
            return;
        }

        std::cout << "\nType the first number:\n";
        std::cin >> value_parser;

        std::cout << "\nType the second number:\n";
        std::cin >> value2_parser;

        auto num1 = tryParse(value_parser);
        auto num2 = tryParse(value2_parser);

        if (num2 == 0 && option.value() == 4) {
            std::cout << "Invalid operation division by 0";
            continue;
        }

        switch (option.value()) {
            case 1:
                std::cout << "\nThe value of " << num1.value() << " plus " << num2.value() << " is " << num1.value() + num2.value();
                break;
            case 2:
                std::cout << "\nThe value of " << num1.value() << " minus " << num2.value() << " is " << num1.value() - num2.value();
                break;
            case 3:
                std::cout << "\nThe value of " << num1.value() << " multiplied by " << num2.value() << " is " << num1.value() * num2.value();
                break;
            case 4:
                std::cout << "\nThe value of " << num1.value() << " divided by " << num2.value() << " is " << (float)num1.value() / num2.value();
                break;
        }
    }
}
