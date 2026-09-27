#include <iostream>
#include <string>

#include "idk.h"

struct User {
    int id;
    std::string name;
    int age;
};


void usersInformation() {
    User users[3] =  {
        { 1, "name1", 1 },
        { 2, "name2", 2 },
        { 3, "name3", 3 }
    };

    while (true) {
        std::string name, option_parser;

        std::cout << "\nList of users: \n";

        for (const auto& u : users) {
            std::cout << "Id: " << u.id << " Name: " << u.name << " Age: " << u.age << "\n";
        }

        std::cout << "\nChoose which you want to modify by id\n\n";
        std::cin >> option_parser;

        auto option = tryParse(option_parser);

        if (option == std::nullopt) {
            continue;
        }

        User* selectedUser = nullptr;
        for (auto& u : users) {
            if (u.id == option.value()) {
                selectedUser = &u;
                break;
            }
        }

        if (selectedUser == nullptr) {
            std::cout << "\nCouldn't find user with this id\n";
            continue;
        }

        std::cout << "What you want to change?\n1 - Name\n2 - Age\n\n";
        std::cin >> option_parser;

        auto option_to_change = tryParse(option_parser);

        if (option_to_change == std::nullopt) {
            continue;
        }

        if (option_to_change.value() == 1) {
            std::cout << "\nWhich is the new name?\n\n";
            std::cin >> name;
            selectedUser->name = name;
        } else if (option_to_change.value() == 2) {
            std::cout << "\nWhich is the new age?\n\n";
            std::cin >> option_parser;
            auto newAge = tryParse(option_parser);
            if (newAge != std::nullopt) {
                selectedUser->age = newAge.value();
            }
        }
    }
}
