#include "../include/program.h"

#include <fstream>

#include "../include/consts.h"
#include "../include/menu.h"
#include "../include/product.h"
#include "../include/utils.h"

Program::Program() = default;
void Program::addProducts() { Product::addProduct(); }

void Program::showProducts() {
    if (isFileEmpty(FILE_WITH_PRODUCTS)) {
        std::cout << "\nError: Product list is empty! Please add a product first (use "
                     "option 1)."
                  << "\n";
        return;
    }

    Product::showProducts();
}

void Program::displayQuantityWithYear() {
    if (isFileEmpty(FILE_WITH_PRODUCTS)) {
        std::cout << "\nError: Product list is empty (use 1 option)."
                  << "\n";
        return;
    }

    int year = getValue<int>("\nEnter year to search for: ");
    int totalQuantity = Product::getQuantityWithYear(year);

    if (totalQuantity == 0) {
        std::cout << "\nNo products" << year << "." << "\n";
        return;
    }

    std::cout << "\nTotal quantity of products received in " << year << ": " << totalQuantity
              << "\n";
}

void Program::runProgram() {
    int choice = 0;

    while (true) {
        showTask();
        showMenu();
        choice = getValue<int>("\nPlease enter menu option: ");

        switch (choice) {
            case 1:
                addProducts();
                break;
            case 2:
                showProducts();
                break;
            case 3:
                displayQuantityWithYear();
                break;
            case 4:
                std::cout << "\nYou have successfully exited the program." << "\n";
                return;
            default:
                std::cout << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << "\n";
        }
    }
}