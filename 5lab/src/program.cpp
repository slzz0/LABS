#include <iostream>
#include "../include/menu.h"

void runProgram() {
    int choice;
    showTaskMenu();
    showMenu();

    while (true) {
        std::cout << "\nSelect a task MENU option: ";
        choice = getValue<int>("");

        switch (choice) {
            case 1:
                findMaxInArray<int>("int");
                break;
            case 2:
                findMaxInArray<double>("double");
                break;
            case 3:
                findMaxInArray<char>("char");
                break;
            case 4:
                std::cout << "Exiting program...";
                return;
            default:
                std::cout << "Error: you have selected an incorrect MENU option";
                break;
        }
    }
}