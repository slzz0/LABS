#include "../include/product.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../include/utils.h"

void Product::addProduct() {
    Product temp;

    std::cout << "\n     Adding New Product " << "\n";

    temp.nomitation = getValue<std::string>("Enter product name: ");

    temp.quantity = getValue<int>("Enter product quantity: ");

    temp.price = getValue<double>("Enter product price: ");

    temp.receiptOfDate.inputDate();

    std::ofstream fileOut;
    fileOut.open(FILE_WITH_PRODUCTS, std::ios::app);

    if (!isValidFileOpen(fileOut, FILE_WITH_PRODUCTS)) {
        return;
    }

    fileOut << temp << " ";

    fileOut.close();
}

void Product::showProducts() {
    std::ifstream fileIn;
    fileIn.open(FILE_WITH_PRODUCTS);

    Product temp;

    if (!isValidFileOpen(fileIn, FILE_WITH_PRODUCTS)) {
        return;
    }

    std::cout << "\n\t\t\t\tPRODUCTS LIST" << "\n";

    std::cout << std::left << std::setw(25) << std::setfill(' ') << "Name" << std::setw(12)
              << std::setfill(' ') << "Quantity" << std::setw(12) << std::setfill(' ') << "Price"
              << std::setw(15) << std::setfill(' ') << "Receipt Date" << "\n";
    std::cout << "------------------------------------------------------------" << "\n";

    while (fileIn >> temp) {
        std::cout << std::left << std::setw(25) << std::setfill(' ')
                  << (temp.nomitation.length() > 24 ? temp.nomitation.substr(0, 22) + ".."
                                                    : temp.nomitation)
                  << std::setw(12) << std::setfill(' ') << temp.quantity << std::setw(12)
                  << std::setfill(' ') << temp.price << std::setw(15) << std::setfill(' ')
                  << temp.receiptOfDate << "\n";
    }

    fileIn.close();
}

int Product::getQuantityWithYear(int year) {
    std::ifstream fileIn;
    fileIn.open(FILE_WITH_PRODUCTS);

    Product tmp;
    int totalQuantity = 0;

    if (!isValidFileOpen(fileIn, FILE_WITH_PRODUCTS)) {
        return 0;
    }

    while (fileIn >> tmp) {
        if (tmp.receiptOfDate.getYear() == year) {
            totalQuantity += tmp.quantity;
        }
    }

    fileIn.close();
    return totalQuantity;
}