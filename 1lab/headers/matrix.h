#pragma once

#include <iostream>

class Matrix {
   private:
    int** data;
    int cols_count;
    int rows_count;

    void allocateMemory(int rows, int cols);
    void freeMemory();

   public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    void inputMatrix();
    void printMatrix() const;
    void multiplyByNumber(int number) const;

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
};
