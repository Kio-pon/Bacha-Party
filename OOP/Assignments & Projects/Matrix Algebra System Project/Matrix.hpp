#ifndef __MATRIX_HPP
#define __MATRIX_HPP

#include <vector>

class Matrix {
public:

    Matrix() = default;
    Matrix(const int rows, const int cols);
    Matrix(Matrix const& other);

    ~Matrix() = default;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    bool   operator==(const Matrix& other) const;

    virtual double getElement(const int row, const int col) const;
    virtual void   setElement(const int row, const int col, const double value);
    int            getRows() const;
    int            getCols() const;

    int getElementsSize() const;

protected:

    int                 rows, cols;
    std::vector<double> elements;
};

#endif  // __MATRIX_HPP

