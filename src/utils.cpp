#include <iostream>
#include <string>
#include <optional>

#include "idk.h"

std::optional<int> tryParse(const std::string& value) {
    try {
        return std::stoi(value);
    } catch (std::exception&) {
        std::cout << "\nA error happened and couldn't work properly blah blah blah try again\n";
        return std::nullopt;
    }
}