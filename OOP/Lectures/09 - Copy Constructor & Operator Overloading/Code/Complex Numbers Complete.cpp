#include <iostream>
#include <cmath>
using namespace std;

/*
    A simple representation of complex numbers with real and imaginary parts.

    Supports:
    - Arithmetic operators (+, -, *, /)
    - Comparison operators (==, !=)
    - Unary operators (+, - , ++, --)
    - Stream output (<<)
    - Utility functions (modulus, conjugate, etc.)
*/

struct ComplexNumber {
    double real;      // Real part of the complex number
    double imaginary; // Imaginary part of the complex number

    // Default constructor initializes the number to 0 + 0i
    ComplexNumber() : real(0), imaginary(0) {}

    // Parameterized constructor to initialize with given real and imaginary parts
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Print function for debugging (not needed if operator<< is defined)
    void print() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

/* ------------------- Addition ------------------- */

// Function-style addition
ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
}

// Operator-style addition
ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
}

/* ------------------- Subtraction ------------------- */

ComplexNumber sub(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real - b.real, a.imaginary - b.imaginary);
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real - b.real, a.imaginary - b.imaginary);
}

/* ------------------- Multiplication ------------------- */

// (a + bi)(c + di) = (ac - bd) + (ad + bc)i
ComplexNumber mul(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real*b.real - a.imaginary*b.imaginary,
                         a.real*b.imaginary + a.imaginary*b.real);
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real*b.real - a.imaginary*b.imaginary,
                         a.real*b.imaginary + a.imaginary*b.real);
}

/* ------------------- Conjugate ------------------- */

// Conjugate: (a + bi) -> (a - bi)
ComplexNumber conjugate(const ComplexNumber& a) {
    return ComplexNumber(a.real, -a.imaginary);
}

// Overloading unary '~' to return conjugate
ComplexNumber operator~(const ComplexNumber& a) {
    return conjugate(a);
}

/* ------------------- Modulus ------------------- */

// Modulus (magnitude): |a + bi| = sqrt(a^2 + b^2)
double mod(const ComplexNumber& a) {
    return sqrt((a.real*a.real) + (a.imaginary*a.imaginary));
}

/* ------------------- Division ------------------- */

// Division by a scalar
ComplexNumber div(const ComplexNumber& a, double b) {
    return ComplexNumber(a.real/b, a.imaginary/b);
} // what if b is zero, that comes under error handling that we have not covered.

ComplexNumber operator/(const ComplexNumber& a, double b) {
    return div(a, b);
}

// Division by another complex number
// (a / b) = (a * conjugate(b)) / |b|^2
ComplexNumber div(const ComplexNumber& a, const ComplexNumber& b) {
    double divisor = mod(b)*mod(b);        // |b|^2
    ComplexNumber multiplied = a * (~b);   // a * conjugate(b)
    return multiplied/divisor;             // divide by scalar
}

ComplexNumber operator/(const ComplexNumber& a, ComplexNumber b) {
    return div(a, b);
}

/* ------------------- Increment & Decrement ------------------- */

/*
 Note:
    Prefix (++c / --c) modifies and returns reference.
    Postfix (c++ / c--) modifies but returns the OLD value.
    
    Returning reference in prefix allows chaining: ++(++c).
*/

// Prefix ++c
ComplexNumber& operator++(ComplexNumber& c) {
    ++c.real;       // increment real part
    ++c.imaginary;  // increment imaginary part 
    return c;
}

// Postfix c++
ComplexNumber operator++(ComplexNumber& c, int) {
    ComplexNumber temp = c; // save old value
    ++c.real;
    ++c.imaginary;          // note: different behavior than prefix
    return temp;            // return old value
}

// Prefix --c
ComplexNumber& operator--(ComplexNumber& c) {
    --c.real;
    --c.imaginary;
    return c;
}

// Postfix c--
ComplexNumber operator--(ComplexNumber& c, int) {
    ComplexNumber temp = c;
    --c.real;
    --c.imaginary;
    return temp;
}

/* ------------------- Comparison Operators ------------------- */

// Equality: real and imaginary parts must be exactly equal
/*
    The following logic looks good but will not work! Can you tell why?
*/
bool operator==(const ComplexNumber& a, const ComplexNumber& b) {
    return a.real == b.real && a.imaginary == b.imaginary;
}

// Inequality
bool operator!=(const ComplexNumber& a, const ComplexNumber& b) {
    return !(a == b);
}

/* ------------------- Unary Operators ------------------- */

// Unary minus: -(a + bi) = -a - bi
ComplexNumber operator-(const ComplexNumber& c) {
    return ComplexNumber(-c.real, -c.imaginary);
}

// Unary plus: +(a + bi) = a + bi (no change)
ComplexNumber operator+(const ComplexNumber& c) {
    return c;
}

/* ------------------- Output Operator ------------------- */

/*
    Stream insertion operator (<<) for printing ComplexNumber objects.
    
    NOTE:
    - You cannot make this operator `const` at the end because:
        - Member functions can be marked const (guaranteeing they don't
        modify the object).
        - Free functions like this do not have an implicit `this` object,
        so adding `const` at the end is meaningless and not allowed.
*/
ostream& operator<<(ostream& os, const ComplexNumber& c) {
    return os << c.real
              << (c.imaginary >= 0 ? " + " : " - ") // ternary operator. Its just an if else statment (see older slides)
              << abs(c.imaginary) << "i";
}

/* ------------------- MAIN ------------------- */

int main() {
    ComplexNumber x(1, 2);
    ComplexNumber y(2, 1);
    ComplexNumber z = x + y;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl; // corrected from "end" to "endl"
    cout << ++z << endl;
    cout << ++(++z) << endl; // this will not work if you remove the return by reference in the prefix increment

    return 0;
}
