#include "../headers/matrix.h"

#include "../headers/utilits.h"

using namespace std;

Matrix::Matrix() : data(nullptr), cols_count(0), rows_count(0) {}
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be a positive number");
    }
    allocateMemory(rows, cols);
}

Matrix::~Matrix() { freeMemory(); }

void Matrix::allocateMemory(int rows, int cols) {
    rows_count = rows;
    cols_count = cols;

    data = new int*[rows_count];
    for (int i = 0; i < rows_count; i++) {
        data[i] = new int[cols_count];
    }
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            data[i][j] = 0;
        }
    }
}

void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows_count; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

void Matrix::inputMatrix() {
    if (data == nullptr) {
        cout << "Enter the number of rows in the matrix: ";
        rows_count = validInt();
        cout << "Enter the number of columns in the matrix: ";
        cols_count = validInt();

        if (rows_count <= 0 || cols_count <= 0) {
            throw std::invalid_argument("Matrix dimensions must be a positive number");
        }

        allocateMemory(rows_count, cols_count);
    }

    cout << "Enter matrix elements " << rows_count << "x" << cols_count << ":\n";
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            data[i][j] = validInt();
        }
    }
}

void Matrix::printMatrix() const {
    if (data == nullptr) {
        cout << "The matrix is not initialized (you must select 1-st option)" << endl;
        return;
    }
    cout << "Matrix " << rows_count << "x" << cols_count << ":\n";
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Matrix::multiplyByNumber(int number) const {
    if (data == nullptr) {
        cout << "The matrix is not initialized (you must select 1-st option)" << endl;
        return;
    }
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            data[i][j] *= number;
        }
    }
    cout << "Matrix multiplied by " << number
         << " successfully! (to see the new matrix select 2-rd option)" << endl;
}

Matrix::Matrix(const Matrix& other) : data(nullptr), cols_count(0), rows_count(0) {
    if (other.data != nullptr && other.rows_count > 0 && other.cols_count > 0) {
        allocateMemory(other.rows_count, other.cols_count);
        for (int i = 0; i < rows_count; i++) {
            for (int j = 0; j < cols_count; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    freeMemory();

    if (other.rows_count > 0 && other.cols_count > 0 && other.data != nullptr) {
        allocateMemory(other.rows_count, other.cols_count);
        for (int i = 0; i < rows_count; i++) {
            for (int j = 0; j < cols_count; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}
