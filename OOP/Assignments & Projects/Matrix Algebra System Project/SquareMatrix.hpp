#ifndef __SQUARE_MATRIX_HPP
#define __SQUARE_MATRIX_HPP

#include "Matrix.hpp"

class SquareMatrix : public Matrix {
public:

    SquareMatrix() = default;
    SquareMatrix(const int size);
    SquareMatrix(SquareMatrix const& other);

    ~SquareMatrix() = default;

    SquareMatrix operator+(const SquareMatrix& other) const;
    SquareMatrix operator-(const SquareMatrix& other) const;
    SquareMatrix operator*(const SquareMatrix& other) const;
    bool         operator==(const SquareMatrix& other) const;

    double getElement(const int row, const int col) const;
    void   setElement(const int row, const int col, const double value);
};

#endif  // __SQUARE_MATRIX_HPP
