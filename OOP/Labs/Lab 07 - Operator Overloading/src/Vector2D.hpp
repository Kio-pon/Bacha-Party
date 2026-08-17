#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <iostream>

/// @brief Class representing a 2D vector with basic arithmetic operations.
class Vector2D {
public:

    Vector2D() = default;
    Vector2D(const double x, const double y);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(const double scalar) const;

    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(const double scalar);

    double operator*(const Vector2D& other) const;  // dot product

    bool operator==(const Vector2D& other) const;
    bool operator!=(const Vector2D& other) const;

    double operator[](int index) const;

    //! Already implemented for you
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);

private:

    double m_x, m_y;
};

#endif  // VECTOR2D_HPP
