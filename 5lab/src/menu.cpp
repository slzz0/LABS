#include "../include/menu.h"

#include <iostream>

#include "../include/utils.h"

void showMenu() {
    std::cout << "\n\t\tMenu\n";
    std::cout << "1. Find maximum in integer array (int)\n";
    std::cout << "2. Find maximum in double array (double)\n";
    std::cout << "3. Find maximum in character array (char)\n";
    std::cout << "4. Exit program\n";
}

void showTaskMenu() {
    std::cout << "\n\t\tTask Menu\n";
    std::cout << "Write a template function that extracts the maximum value in an array\n\n";
}

template <typename T>
void findMaxInArray(const char* name) {
    std::cout << "\nWorking with " << name << " type\n";
    int size;
    while (true) {
        size = getValue<int>("Enter array size: ");
        if (size > 0) {
            break;
        }
        std::cout << "Size must be positive. Please try again.\n";
    }

    auto* arr = new T[size];
    inputArray(arr, size);
    showArray(arr, size);

    T maxValue = findMax(arr, arr + size);
    std::cout << "Max value is: " << maxValue << "\n";

    delete[] arr;
}
template void findMaxInArray<int>(const char* name);
template void findMaxInArray<double>(const char* name);
template void findMaxInArray<char>(const char* name);