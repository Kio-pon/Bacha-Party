#include <iostream>
#include <tuple>

#include "Time.hpp"

#define GREEN  "\033[1;32m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

inline int toSeconds(const int h, const int m, const int s) {
    return h * 3600 + m * 60 + s;
}

inline int toSeconds(const Time &t) {
    return toSeconds(t.getHours(), t.getMinutes(), t.getSeconds());
}

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

void testConstructors() {
    std::cout << YELLOW << "\n--- Constructor Tests ---\n" << RESET;

    struct {
        int h, m, s, expected;
    } cases[] = {
        { 1,  1,  1,        3661},
        {25, 10, 23, toSeconds(1,10, 23)},
        { 0,  0,  0,           0          },
        { 2, 59, 60, toSeconds(3,0, 0)},
        {48,  0,  0,           0   }
    };

    for (auto &c : cases) {
        Time t(c.h, c.m, c.s);
        check(toSeconds(t) == c.expected,
              "Time(" + std::to_string(c.h) + ":" + std::to_string(c.m) + ":" +
                  std::to_string(c.s) + ") converts correctly");
    }

    Time t1(3661), t2(1, 1, 1);
    check(toSeconds(t1) == toSeconds(t2),
          "Construct from seconds: 3661 == 1:1:1");
}

void testAddition() {
    std::cout << YELLOW << "\n--- Addition Tests ---\n" << RESET;

    struct {
        Time lhs;
        Time rhs;
        int  rhs_seconds;
        int  expected;
    } cases[] = {
        { Time(1, 20, 30), Time(0, 50, 45), toSeconds(0,          50, 45),
         toSeconds(1, 20, 30) + toSeconds(0, 50, 45)},
        {Time(23, 59, 30), Time(0,  0, 45),          45, toSeconds(0,   0, 15)   },
        { Time(2, 10,  0), Time(1, 50,  0), toSeconds(1,          50,  0),
         toSeconds(4,  0,                0)   }
    };

    for (auto &c : cases) {
        check(toSeconds(c.lhs + c.rhs) == c.expected, "lhs + rhs == expected");
        check(toSeconds(c.lhs + c.rhs_seconds) == c.expected,
              "lhs + rhs_seconds == expected");
    }
}

void testSubtraction() {
    std::cout << YELLOW << "\n--- Subtraction Tests ---\n" << RESET;

    struct {
        Time lhs;
        Time rhs;
        int  rhs_seconds;
        int  expected;
    } cases[] = {
        {Time(2, 10,  0), Time(1, 50,  0), toSeconds(1, 50,  0),
         toSeconds(2, 10,  0) - toSeconds(1, 50,  0)},
        {Time(1,  0,  0), Time(0, 59, 59), toSeconds(0, 59, 59),
         toSeconds(1,  0,  0) - toSeconds(0, 59, 59)},
        {Time(0,  0, 30), Time(0,  0,  0), toSeconds(0,  0,  0),
         toSeconds(0,  0, 30) - toSeconds(0,  0,  0)}
    };

    for (auto &c : cases) {
        check(toSeconds(c.lhs - c.rhs) == c.expected, "lhs - rhs == expected");
        check(toSeconds(c.lhs - c.rhs_seconds) == c.expected,
              "lhs - rhs_seconds == expected");
    }
}

void testEquality() {
    std::cout << YELLOW << "\n--- Equality Tests ---\n" << RESET;

    struct {
        Time lhs;
        Time rhs;
        int  rhs_seconds;
        bool expected;
    } cases[] = {
        {Time(1, 0, 0), Time(1,  0,  0), 3600,  true},
        {Time(1, 0, 0), Time(0, 59, 59), 3599, false}
    };

    for (auto &c : cases) {
        check((toSeconds(c.lhs) == toSeconds(c.rhs)) == c.expected,
              "lhs == rhs");
        check((toSeconds(c.lhs) == c.rhs_seconds) == c.expected,
              "lhs == rhs_seconds");
        check((toSeconds(c.lhs) != toSeconds(c.rhs)) == !c.expected,
              "lhs != rhs");
        check((toSeconds(c.lhs) != c.rhs_seconds) == !c.expected,
              "lhs != rhs_seconds");
    }
}

void testComparison() {
    std::cout << YELLOW << "\n--- Comparison Tests ---\n" << RESET;

    struct {
        Time lhs;
        Time rhs;
        int  rhs_seconds;
        bool expectedLess;
        bool expectedGreater;
    } cases[] = {
        {Time(1, 0, 0), Time(2,  0,  0), 7200,  true, false},
        {Time(1, 0, 0), Time(0, 59, 59), 3599, false,  true},
        {Time(2, 0, 0), Time(1,  0,  0), 3600, false,  true},
        {Time(1, 0, 0), Time(1,  0,  1), 3601,  true, false}
    };

    for (auto &c : cases) {
        int lhs_sec = toSeconds(c.lhs);
        int rhs_sec = toSeconds(c.rhs);

        check((lhs_sec < rhs_sec) == c.expectedLess, "lhs < rhs");
        check((lhs_sec < c.rhs_seconds) == c.expectedLess, "lhs < rhs_seconds");
        check((lhs_sec > rhs_sec) == c.expectedGreater, "lhs > rhs");
        check((lhs_sec > c.rhs_seconds) == c.expectedGreater,
              "lhs > rhs_seconds");
    }
}

int main() {
    testConstructors();
    testAddition();
    testSubtraction();
    testEquality();
    testComparison();

    std::cout << "\n----------------------------------------\n";
    std::cout << "Total: " << (passed + failed) << " | " << GREEN
              << "Passed: " << passed << RESET << " | " << RED
              << "Failed: " << failed << RESET
              << "\n----------------------------------------\n";

    return failed == 0 ? 0 : 1;
}
