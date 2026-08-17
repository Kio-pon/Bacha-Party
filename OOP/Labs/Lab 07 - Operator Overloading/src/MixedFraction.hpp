#ifndef MIXED_FRACTION_HPP
#define MIXED_FRACTION_HPP

#include <iostream>

/// @brief Class representing a mixed fraction (whole + numerator/denominator).
/// Example: 2 3/4 (two and three-fourths)
class MixedFraction {
public:

    MixedFraction() = default;
    MixedFraction(const int whole, const int numerator, const int denominator);

    int getWhole() const;
    int getNumerator() const;
    int getDenominator() const;

    MixedFraction operator+(const MixedFraction& other) const;
    MixedFraction operator-(const MixedFraction& other) const;
    MixedFraction operator*(const MixedFraction& other) const;
    MixedFraction operator/(const MixedFraction& other) const;

    MixedFraction& operator+=(const MixedFraction& other);
    MixedFraction& operator-=(const MixedFraction& other);
    MixedFraction& operator*=(const MixedFraction& other);
    MixedFraction& operator/=(const MixedFraction& other);

    bool operator==(const MixedFraction& other) const;
    bool operator!=(const MixedFraction& other) const;

    //! Already implemented for you
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mf);

private:

    int m_whole, m_numerator, m_denominator;

    /// @brief Normalizes the fraction (e.g., 3/2 becomes 1 1/2).
    void normalize();
};

#endif  // MIXED_FRACTION_HPP
