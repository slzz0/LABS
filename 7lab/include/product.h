#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "../include/date.h"


class Product {
   private:
    std::string nomitation;
    int quantity = 0;
    double price = 0.0;
    Date receiptOfDate;

   public:
    Product() = default;
    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        os << product.nomitation << "|" << product.quantity << " " << product.price << " "
           << product.receiptOfDate;

        return os;
    }

    friend std::istream& operator>>(std::istream& is, Product& product) {
        std::getline(is, product.nomitation, '|');

        is >> product.quantity >> product.price >> product.receiptOfDate;

        if (is.peek() == ' ') {
            is.ignore();
        }
        return is;
    }

    static void showProducts();
    static void addProduct();
    static int getQuantityWithYear(int year);
};