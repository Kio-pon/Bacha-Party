#include <iostream>
#include <stdexcept>
#include <string>

#include "MixedFraction.hpp"

#define GREEN  "\033[1;32m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"
#define CYAN   "\033[1;36m"

int testsPassed = 0;
int testsFailed = 0;

void printResult(const std::string& testName, bool passed) {
    if (passed) {
        std::cout << GREEN << "[PASS] " << RESET << testName << "\n";
        ++testsPassed;
    } else {
        std::cout << RED << "[FAIL] " << RESET << testName << "\n";
        ++testsFailed;
    }
}

bool equalMixed(const MixedFraction& a, const MixedFraction& b) {
    return a.getWhole() == b.getWhole() &&
           a.getNumerator() == b.getNumerator() &&
           a.getDenominator() == b.getDenominator();
}

void testAddition() {
    MixedFraction a(1, 1, 2);
    MixedFraction b(2, 1, 2);
    MixedFraction result = a + b;
    printResult("AdditionOperator", equalMixed(result, MixedFraction(4, 0, 1)));
}

void testSubtraction() {
    MixedFraction a(3, 1, 2);
    MixedFraction b(1, 1, 2);
    MixedFraction result = a - b;
    printResult("SubtractionOperator",
                equalMixed(result, MixedFraction(2, 0, 1)));
}

void testMultiplication() {
    MixedFraction a(1, 1, 2);
    MixedFraction b(2, 0, 1);
    MixedFraction result = a * b;
    printResult("MultiplicationOperator",
                equalMixed(result, MixedFraction(3, 0, 1)));
}

void testDivision() {
    MixedFraction a(3, 0, 1);
    MixedFraction b(1, 1, 2);
    MixedFraction result = a / b;
    printResult("DivisionOperator", equalMixed(result, MixedFraction(2, 0, 1)));
}

void testPlusEqual() {
    MixedFraction a(1, 1, 2);
    MixedFraction b(0, 1, 2);
    a += b;
    printResult("PlusEqualOperator", equalMixed(a, MixedFraction(2, 0, 1)));
}

void testMinusEqual() {
    MixedFraction a(2, 1, 2);
    MixedFraction b(1, 1, 2);
    a -= b;
    printResult("MinusEqualOperator", equalMixed(a, MixedFraction(1, 0, 1)));
}

void testTimesEqual() {
    MixedFraction a(1, 0, 1);
    MixedFraction b(0, 3, 2);
    a *= b;
    printResult("TimesEqualOperator", equalMixed(a, MixedFraction(1, 1, 2)));
}

void testDivideEqual() {
    MixedFraction a(2, 0, 1);
    MixedFraction b(1, 0, 1);
    a /= b;
    printResult("DivideEqualOperator", equalMixed(a, MixedFraction(2, 0, 1)));
}

void testEquality() {
    bool pass = (MixedFraction(1, 1, 2) == MixedFraction(1, 1, 2)) &&
                !(MixedFraction(2, 0, 1) == MixedFraction(1, 1, 2));
    printResult("EqualityOperator", pass);
}

void testInequality() {
    bool pass = (MixedFraction(2, 1, 3) != MixedFraction(1, 2, 3)) &&
                !(MixedFraction(3, 0, 1) != MixedFraction(3, 0, 1));
    printResult("InequalityOperator", pass);
}

void testNormalization() {
    MixedFraction mf(1, 5, 2);
    printResult("Normalization", equalMixed(mf, MixedFraction(3, 1, 2)));
}

int main() {
    std::cout << CYAN << "Running MixedFraction Tests...\n" << RESET;

    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testPlusEqual();
    testMinusEqual();
    testTimesEqual();
    testDivideEqual();
    testEquality();
    testInequality();
    testNormalization();

    std::cout << "\n----------------------------------------\n";
    std::cout << "Total: " << (testsPassed + testsFailed) << " | " << GREEN
              << "Passed: " << testsPassed << RESET << " | " << RED
              << "Failed: " << testsFailed << RESET
              << "\n----------------------------------------\n";

    return testsFailed == 0 ? 0 : 1;
}
