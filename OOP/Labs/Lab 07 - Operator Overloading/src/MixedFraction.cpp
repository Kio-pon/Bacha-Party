#include "MixedFraction.hpp"

// Exercise 3 [50 points]: implement the MixedFraction class declared in
// MixedFraction.hpp (whole number + numerator/denominator, kept normalized).

/// @brief Computes the greatest common divisor of two integers.
/// @param a first integer
/// @param b second integer
/// @return The greatest common divisor of a and b.
int gcd(const int a, const int b)
{
    // TODO: implement gcd (e.g. Euclidean algorithm)
    return 1;
}

/// @brief Stream output operator for `MixedFraction`
/// @param os The output stream
/// @param mf The mixed fraction to output
/// @return The output stream
std::ostream &operator<<(std::ostream &os, const MixedFraction &mf)
{
    os << "MixedFraction(" << mf.m_whole << " " << mf.m_numerator << "/"
       << mf.m_denominator << ")";
    return os;
}

MixedFraction::MixedFraction(const int whole, const int numerator,
                              const int denominator)
{
    // TODO: store whole/numerator/denominator (carrying over any numerator
    // overflow into the whole part), then normalize()
}

int MixedFraction::getWhole() const { return m_whole; }

int MixedFraction::getNumerator() const { return m_numerator; }

int MixedFraction::getDenominator() const { return m_denominator; }

void MixedFraction::normalize()
{
    // TODO: reduce m_numerator/m_denominator by their gcd
}

MixedFraction MixedFraction::operator+(const MixedFraction &other) const
{
    // TODO: add two mixed fractions
    return MixedFraction();
}

MixedFraction MixedFraction::operator-(const MixedFraction &other) const
{
    // TODO: subtract other from this (reuse operator+ with a negated value)
    return MixedFraction();
}

MixedFraction MixedFraction::operator*(const MixedFraction &other) const
{
    // TODO: multiply two mixed fractions
    return MixedFraction();
}

MixedFraction MixedFraction::operator/(const MixedFraction &other) const
{
    // TODO: divide this by other (reuse operator* with the reciprocal)
    return MixedFraction();
}

MixedFraction &MixedFraction::operator+=(const MixedFraction &other)
{
    // TODO: add in place, return *this
    return *this;
}

MixedFraction &MixedFraction::operator-=(const MixedFraction &other)
{
    // TODO: subtract in place, return *this
    return *this;
}

MixedFraction &MixedFraction::operator*=(const MixedFraction &other)
{
    // TODO: multiply in place, return *this
    return *this;
}

MixedFraction &MixedFraction::operator/=(const MixedFraction &other)
{
    // TODO: divide in place, return *this
    return *this;
}

bool MixedFraction::operator==(const MixedFraction &other) const
{
    // TODO: compare as equivalent fractions (cross-multiply to avoid
    // needing a common denominator)
    return false;
}

bool MixedFraction::operator!=(const MixedFraction &other) const
{
    // TODO: negate operator==
    return false;
}
