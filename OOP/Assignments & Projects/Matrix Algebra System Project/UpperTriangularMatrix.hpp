#ifndef __UPPER_TRIANGULAR_MATRIX_HPP
#define __UPPER_TRIANGULAR_MATRIX_HPP

#include "SquareMatrix.hpp"

class UpperTriangularMatrix : public SquareMatrix {
public:

    UpperTriangularMatrix() = default;
    UpperTriangularMatrix(const int size);
    UpperTriangularMatrix(UpperTriangularMatrix const& other);
    ~UpperTriangularMatrix() = default;

    UpperTriangularMatrix operator+(const UpperTriangularMatrix& other) const;
    UpperTriangularMatrix operator-(const UpperTriangularMatrix& other) const;
    UpperTriangularMatrix operator*(const UpperTriangularMatrix& other) const;
    bool                  operator==(const UpperTriangularMatrix& other) const;

    double getElement(const int row, const int col) const;
    void   setElement(const int row, const int col, const double value);
};

#endif  // __UPPER_TRIANGULAR_MATRIX_HPP
