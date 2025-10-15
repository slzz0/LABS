#pragma once

#include "../include/product.h"

class Program
{
    Product product;

    static void addProducts();
    static void showProducts();
    static void displayQuantityWithYear();

  public:
    Program();
    static void runProgram();
};