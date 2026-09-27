// this is just a huge mess of random stuff i'm doing while learning Cpp

#include <iostream>
#include <string>

#include "idk.h"

using namespace std;

int main() {
    while (true) {
        std::string option_parser;

        cout << "\nWelcome to some weird and bad projects I've done\n1 - Just those casual bad calculators\n2 - Weird ahh stuff using pointers and shi\n0 - Quit\n";
        cin >> option_parser;

        auto option = tryParse(option_parser);

        if (option == nullopt) {
            continue;
        }

        switch (option.value()) {
            case 1:
                calculator();
                break;
            case 2:
                usersInformation();
                break;
            case 0:
                return 0;
        }
    }
}