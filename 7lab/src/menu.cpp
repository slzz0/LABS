#include <iostream>
#include "../include/menu.h"

void showMenu()
{
    std::cout << "\n\tMENU" << "\n";
    std::cout << "1. Add a new product" << "\n";
    std::cout << "2. Show all products" << "\n";
    std::cout << "3. Find quantity with year" << "\n";
    std::cout << "4. Exit program" << "\n";
}

void showTask()
{
    std::cout << "\n\t\t\tTASK" << std::endl;
    std::cout << "Create a class Product." << std::endl;
    std::cout << "Class fields: name, quantity, price, receipt date." << std::endl;
    std::cout << "Implement the following:" << std::endl;
    std::cout << " - overload operators << and >> for file I/O," << std::endl;
    std::cout << " - method to get product quantity by specified year." << std::endl;
    std::cout << "Check the work of these methods." << std::endl;
}