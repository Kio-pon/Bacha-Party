#include <iostream>
#include <stdexcept>
#include <tuple>

#include "Vector2D.hpp"

#define GREEN  "\033[1;32m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define CYAN   "\033[1;36m"
#define RESET  "\033[0m"

int passed = 0;
int failed = 0;

void check(bool cond, const std::string &msg) {
    if (cond) {
        std::cout << GREEN << "[PASSED]" << RESET << " " << msg << std::endl;
        ++passed;
    } else {
        std::cerr << RED << "[FAILED]" << RESET << " " << msg << std::endl;
        ++failed;
    }
}

bool approxEqual(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}

void testAdditionAndSubtraction() {
    std::cout << CYAN << "\n--- Addition & Subtraction Tests ---\n" << RESET;

    std::tuple<Vector2D, Vector2D, double> cases[] = {
        { Vector2D(1, 2), Vector2D(3,  4), 11.0},
        {Vector2D(-1, 2), Vector2D(1, -2), -5.0},
        { Vector2D(0, 0), Vector2D(5,  6),  0.0}
    };

    for (auto &[v1, v2, dot] : cases) {
        Vector2D sum  = v1 + v2;
        Vector2D diff = v1 - v2;

        check(approxEqual(sum[0], v1[0] + v2[0]) &&
                  approxEqual(sum[1], v1[1] + v2[1]),
              "v1 + v2 == element-wise addition");
        check(approxEqual(diff[0], v1[0] - v2[0]) &&
                  approxEqual(diff[1], v1[1] - v2[1]),
              "v1 - v2 == element-wise subtraction");
    }
}

void testScalarOps() {
    std::cout << CYAN << "\n--- Scalar Multiplication & Division Tests ---\n"
              << RESET;

    Vector2D v1(2.0, 3.0);
    double   scalar = 2.5;
    Vector2D result = v1 * scalar;
    check(approxEqual(result[0], 5.0) && approxEqual(result[1], 7.5),
          "v * scalar");
}

void testDotProduct() {
    std::cout << CYAN << "\n--- Dot Product Tests ---\n" << RESET;

    std::tuple<Vector2D, Vector2D, double> cases[] = {
        { Vector2D(1, 2), Vector2D(3,  4), 11.0},
        {Vector2D(-1, 2), Vector2D(1, -2), -5.0},
        { Vector2D(0, 0), Vector2D(5,  6),  0.0}
    };

    for (auto &[v1, v2, expectedDot] : cases) {
        check(approxEqual(v1 * v2, expectedDot),
              "v1 * v2 == " + std::to_string(expectedDot));
    }
}

void testCompoundOps() {
    std::cout << CYAN << "\n--- Compound Operator Tests ---\n" << RESET;

    Vector2D v1(1, 1);
    Vector2D v2(2, 3);
    v1 += v2;
    check(v1 == Vector2D(3, 4), "v1 += v2");

    Vector2D v3(5, 5);
    Vector2D v4(2, 3);
    v3 -= v4;
    check(v3 == Vector2D(3, 2), "v1 -= v2");

    Vector2D v5(3, 4);
    v5 *= 2;
    check(v5 == Vector2D(6, 8), "v *= scalar");
}

void testComparisonOps() {
    std::cout << CYAN << "\n--- Comparison Operator Tests ---\n" << RESET;

    check(Vector2D(1.0, 2.0) == Vector2D(1.0, 2.0), "Equality true");
    check(!(Vector2D(1.0, 2.0) == Vector2D(2.0, 1.0)), "Equality false");

    check(Vector2D(1.0, 2.0) != Vector2D(2.0, 1.0), "Inequality true");
    check(!(Vector2D(1.0, 2.0) != Vector2D(1.0, 2.0)), "Inequality false");
}

void testIndexOp() {
    std::cout << CYAN << "\n--- Index Operator Tests ---\n" << RESET;

    Vector2D v(3.5, 7.5);
    check(approxEqual(v[0], 3.5), "v[0] == 3.5");
    check(approxEqual(v[1], 7.5), "v[1] == 7.5");
}

int main() {
    testAdditionAndSubtraction();
    testScalarOps();
    testDotProduct();
    testCompoundOps();
    testComparisonOps();
    testIndexOp();

    std::cout << "\n----------------------------------------\n";
    std::cout << "Total: " << (passed + failed) << " | " << GREEN
              << "Passed: " << passed << RESET << " | " << RED
              << "Failed: " << failed << RESET
              << "\n----------------------------------------\n";

    return failed == 0 ? 0 : 1;
}
