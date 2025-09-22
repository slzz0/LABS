#include "../headers/menu.h"

#include <iostream>

void taskMenu() {
    std::cout << "\n\t\t\tTASK" << std::endl;
    std::cout << "Create a class Matrix." << std::endl;
    std::cout << "Allocate memory for the matrix dynamically." << std::endl;
    std::cout << "Define a default constructor and a constructor with parameters." << std::endl;
    std::cout << "Implement the following methods:" << std::endl;
    std::cout << " - input data into the matrix," << std::endl;
    std::cout << " - display the matrix," << std::endl;
    std::cout << " - multiply the matrix by a number." << std::endl;
    std::cout << "Check the work of these methods." << std::endl;

    std::cout << "\n\t\t\tMENU" << std::endl;
    std::cout << "1. Enter the matrix." << std::endl;
    std::cout << "2. Display the matrix." << std::endl;
    std::cout << "3. Multiply the matrix by a number." << std::endl;
    std::cout << "4. Exit the program." << std::endl;
}
