#include "Vector2D.hpp"

/// @brief Stream output operator for `Vector2D`
/// @param os The output stream
/// @param v The vector to output
/// @return The output stream
std::ostream &operator<<(std::ostream &os, const Vector2D &v)
{
    os << "Vector2D(" << v.m_x << ", " << v.m_y << ")";
    return os;
}

// Exercise 2 [25 points]: implement the Vector2D class declared in
// Vector2D.hpp. Overloaded operators must return new objects (except
// compound assignment). Assume scalars are non-zero.

Vector2D::Vector2D(const double x, const double y)
{
    // TODO: initialize m_x and m_y
}

Vector2D Vector2D::operator+(const Vector2D &other) const
{
    // TODO: component-wise addition
    return Vector2D();
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    // TODO: component-wise subtraction
    return Vector2D();
}

Vector2D Vector2D::operator*(const double scalar) const
{
    // TODO: scalar multiplication
    return Vector2D();
}

Vector2D &Vector2D::operator+=(const Vector2D &other)
{
    // TODO: add in place, return *this
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other)
{
    // TODO: subtract in place, return *this
    return *this;
}

Vector2D &Vector2D::operator*=(const double scalar)
{
    // TODO: scale in place, return *this
    return *this;
}

double Vector2D::operator*(const Vector2D &other) const
{
    // TODO: dot product
    return 0.0;
}

bool Vector2D::operator==(const Vector2D &other) const
{
    // TODO: component-wise equality
    return false;
}

bool Vector2D::operator!=(const Vector2D &other) const
{
    // TODO: negate operator==
    return false;
}

double Vector2D::operator[](int index) const
{
    // TODO: return m_x for index 0, m_y for index 1
    return 0.0;
}
