#include "../include/menu.h"

#include <iostream>

void showMenu() {
    std::cout << "\n\t MENU" << "\n";
    std::cout << "1. Create ring" << "\n";
    std::cout << "2. Add element" << "\n";
    std::cout << "3. Remove element" << "\n";
    std::cout << "4. Display ring" << "\n";
    std::cout << "5. Sort ring" << "\n";
    std::cout << "6. Search for element" << "\n";
    std::cout << "7. Clear ring" << "\n";
    std::cout << "8. End the program" << "\n";
}

void showAddMenu() {
    std::cout << "\n\tADD MENU" << "\n";
    std::cout << "1. Add to the begin" << "\n";
    std::cout << "2. Add to the end" << "\n";
}

void showRemoveMenu() {
    std::cout << "\n\tREMOVE MENU" << "\n";
    std::cout << "1. Remove from the begin" << "\n";
    std::cout << "2. Remove from the end" << "\n";
}

void selectRingType(){
    std::cout << "1. int" << "\n";
    std::cout << "2. long" << "\n";
    std::cout << "3. float" << "\n";
    std::cout << "4. double" << "\n";
    std::cout << "5. char" << "\n";
    std::cout << "6. string" << "\n";
}