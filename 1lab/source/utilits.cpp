#include "../headers/utilits.h"

#include <iostream>

int validInt() {
    int number;
    while (true) {
        if (!(std::cin >> number)) {
            std::cout << "Please enter a valid number: ";
        } else if (std::cin.get() != '\n') {
            std::cout << "Please enter only numbers without characters, try again: ";
        } else {
            return number;
        }
        
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
}