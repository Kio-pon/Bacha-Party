#ifndef __DIAGONAL_MATRIX_HPP
#define __DIAGONAL_MATRIX_HPP

#include "SquareMatrix.hpp"

class DiagonalMatrix : public SquareMatrix {
public:

    DiagonalMatrix() = default;
    DiagonalMatrix(const int size);
    DiagonalMatrix(DiagonalMatrix const& other);
    ~DiagonalMatrix() = default;

    DiagonalMatrix operator+(const DiagonalMatrix& other) const;
    DiagonalMatrix operator-(const DiagonalMatrix& other) const;
    DiagonalMatrix operator*(const DiagonalMatrix& other) const;
    bool           operator==(const DiagonalMatrix& other) const;

    double getElement(const int row, const int col) const;
    void   setElement(const int row, const int col, const double value);
};

#endif  // __DIAGONAL_MATRIX_HPP
