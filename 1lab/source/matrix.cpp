#include "../headers/matrix.h"

#include "../headers/utilits.h"

using namespace std;

Matrix::Matrix() : data(nullptr), cols(0), rows(0) {}
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be a positive number");
    }
    allocateMemory(rows, cols);
}

Matrix::~Matrix() { freeMemory(); }

void Matrix::allocateMemory(int rows, int cols) {
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
    }
}

void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

void Matrix::inputMatrix() {
    if (data == nullptr) {
        cout << "Enter the number of rows in the matrix: ";
        rows = validInt();
        cout << "Enter the number of columns in the matrix: ";
        cols = validInt();

        allocateMemory(rows, cols);
    }

    cout << "Enter matrix elements " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    cout << "Matrix " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] *= number;
        }
    }
    cout << "Matrix multiplied by " << number
         << " successfully! (to see the new matrix select 2-rd option)" << endl;
}

Matrix::Matrix(const Matrix& other) : data(nullptr), cols(0), rows(0) {
    if (other.data != nullptr && other.rows > 0 && other.cols > 0) {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    freeMemory();

    if (other.rows > 0 && other.cols > 0 && other.data != nullptr) {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}
