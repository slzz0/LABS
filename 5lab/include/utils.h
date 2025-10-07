#pragma once
#include <iostream>

template <typename T>
T findMax(const T* begin, const T* end) {
    if (begin == end || begin == nullptr || end == nullptr) {
        std::cout << "The array is empty.";
        return T();
    }

    T maxValue = *begin;
    for (const T* it = begin + 1; it != end; it++) {
        if (*it > maxValue) {
            maxValue = *it;
        }
    }
    return maxValue;
}

template <typename T>
T getValue(const char* prompt) {
    T value;
    std::cout << prompt;

    while (true) {
        if (std::cin >> value) {
            if (std::cin.get() == '\n') {
                return value;
            }
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof());
            std::cout << "Invalid input. Please enter a valid value: ";
        } else {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof());
            std::cout << "Invalid input. Please enter a valid value: ";
        }
    }
}

template <typename T>
void inputArray(T* array, int size) { 
    std::cout << "Enter " << size << " elements:\n";  
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": "; 
        array[i] = getValue<T>("");
    }
}

template <typename T>
void showArray(T* array, int size) {
    std::cout << "\nArray: [";
    for (int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}