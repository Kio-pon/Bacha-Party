#ifndef __LOWER_TRIANGULAR_MATRIX_HPP
#define __LOWER_TRIANGULAR_MATRIX_HPP

#include "SquareMatrix.hpp"

class LowerTriangularMatrix : public SquareMatrix {
public:

    LowerTriangularMatrix() = default;
    LowerTriangularMatrix(const int size);
    LowerTriangularMatrix(LowerTriangularMatrix const& other);
    ~LowerTriangularMatrix() = default;

    LowerTriangularMatrix operator+(const LowerTriangularMatrix& other) const;
    LowerTriangularMatrix operator-(const LowerTriangularMatrix& other) const;
    LowerTriangularMatrix operator*(const LowerTriangularMatrix& other) const;
    bool                  operator==(const LowerTriangularMatrix& other) const;

    double getElement(const int row, const int col) const;
    void   setElement(const int row, const int col, const double value);
};

#endif  // __LOWER_TRIANGULAR_MATRIX_HPP
