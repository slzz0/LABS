#include <iostream>
#include "../include/utils.h"

int myStrlen(const char *string){
    if(string == nullptr){
        return 0;
    }
    int length = 0;

    for(int index = 0; string[index]!= '\0'; index++){
        length++;
    }

    return length;
}

int validation() {
    int number;

    while (true) {
        if (!(std::cin >> number)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter a valid number: ";
            continue;
        }

        if (std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter only numbers without characters: ";
            continue;
        }

        if (number < 0) {
            std::cout << "Please enter a non-negative number: ";
            continue;
        }

        return number;
    }
}