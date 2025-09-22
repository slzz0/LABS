#pragma once
#include <iostream>

#include "../headers/utilits.h"

class Array {
   private:
    int* data = nullptr;
    int size = 0;

    void allocateMemory(int size);
    void freeMemory();

   public:
    Array() = default;
    explicit Array(int size);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    bool contains(int value) const;

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << "[";
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i];
            if (i < arr.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
        arr.freeMemory();
        std::cout << "Enter the size of array: ";
        int newSize = validInt();

        while (newSize <= 0) {
            std::cout << "Size must be positive, try again: ";
            newSize = validInt();
        }
        arr.allocateMemory(newSize);
        arr.size = newSize;
        std::cout << "Enter " << newSize << " elements:\n";
        for (int i = 0; i < newSize; i++) {
            std::cout << "Element " << i + 1 << ": ";
            arr.data[i] = validInt();
        }
        return is;
    }

    friend Array operator&(const Array& lhs, const Array& rhs) {
        Array result;
        if (lhs.data == nullptr || lhs.size == 0) {
            return result;
        }
        if (rhs.data == nullptr || rhs.size == 0) {
            return result;
        }

        for (int i = 0; i < lhs.size; i++) {
            if (rhs.contains(lhs.data[i]) && !result.contains(lhs.data[i])) {
                auto newData = new int[result.size + 1];
                for (int j = 0; j < result.size; j++) {
                    newData[j] = result.data[j];
                }
                newData[result.size] = lhs.data[i];
                delete[] result.data;
                result.data = newData;
                result.size++;
            }
        }
        return result;
    }
};
