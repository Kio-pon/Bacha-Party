#ifndef TEST_TIME
#define TEST_TIME

#include <gtest/gtest.h>

#include <iostream>
#include <tuple>

#include "../src/Time.hpp"

inline int toSeconds(const int h, const int m, const int s) {
    return h * 3600 + m * 60 + s;
}

/* ===========================================================================
   Constructor Tests
   ===========================================================================
 */

struct ConstructorParam {
    int h, m, s, expected_seconds;
};

class TimeConstructorTest : public ::testing::TestWithParam<ConstructorParam> {
};

TEST_P(TimeConstructorTest, ConstructsFromHMS) {
    auto [h, m, s, expected] = GetParam();
    Time t(h, m, s);
    EXPECT_TRUE(t == expected) << "Expected " << expected << " seconds for "
                               << h << ":" << m << ":" << s;
}

INSTANTIATE_TEST_SUITE_P(
    Constructors, TimeConstructorTest,
    ::testing::Values(ConstructorParam{1, 1, 1, 3661},
                      ConstructorParam{25, 10, 23, toSeconds(1, 10, 23)},
                      ConstructorParam{0, 0, 0, 0},
                      ConstructorParam{2, 59, 60, toSeconds(3, 0, 0)},
                      ConstructorParam{48, 0, 0, 0}));

TEST(TimeConstructor, ConstructsFromSeconds) {
    EXPECT_TRUE(Time(3661) == Time(1, 1, 1));
    // EXPECT_TRUE(Time(86400) == 0);
}

/* ===========================================================================
   Operator+ Tests
   ===========================================================================
 */

struct AddParam {
    Time lhs;
    Time rhs;
    int  rhs_seconds;
    int  expected;
};

class TimeAdditionTest : public ::testing::TestWithParam<AddParam> {};

TEST_P(TimeAdditionTest, AddTimeObjects) {
    auto [lhs, rhs, rhs_seconds, expected] = GetParam();
    EXPECT_TRUE(lhs + rhs == expected);
}

TEST_P(TimeAdditionTest, AddIntegerSeconds) {
    auto [lhs, rhs, rhs_seconds, expected] = GetParam();
    EXPECT_TRUE(lhs + rhs_seconds == expected);
}

INSTANTIATE_TEST_SUITE_P(
    AdditionOps, TimeAdditionTest,
    ::testing::Values(
        AddParam{Time(1, 20, 30), Time(0, 50, 45), toSeconds(0, 50, 45),
                 toSeconds(1, 20, 30) + toSeconds(0, 50, 45)},
        AddParam{Time(23, 59, 30), Time(0, 0, 45), 45, toSeconds(0, 0, 15)},
        AddParam{Time(2, 10, 0), Time(1, 50, 0), toSeconds(1, 50, 0),
                 toSeconds(4, 0, 0)}));

/* ===========================================================================
   Operator- Tests
   ===========================================================================
 */

struct SubParam {
    Time lhs;
    Time rhs;
    int  rhs_seconds;
    int  expected;
};

class TimeSubtractionTest : public ::testing::TestWithParam<SubParam> {};

TEST_P(TimeSubtractionTest, SubtractTimeObjects) {
    auto [lhs, rhs, rhs_seconds, expected] = GetParam();
    EXPECT_TRUE(lhs - rhs == expected);
}

TEST_P(TimeSubtractionTest, SubtractIntegerSeconds) {
    auto [lhs, rhs, rhs_seconds, expected] = GetParam();
    EXPECT_TRUE(lhs - rhs_seconds == expected);
}

INSTANTIATE_TEST_SUITE_P(
    SubtractionOps, TimeSubtractionTest,
    ::testing::Values(SubParam{Time(2, 10, 0), Time(1, 50, 0),
                               toSeconds(1, 50, 0),
                               toSeconds(2, 10, 0) - toSeconds(1, 50, 0)},
                      SubParam{Time(1, 0, 0), Time(0, 59, 59),
                               toSeconds(0, 59, 59),
                               toSeconds(1, 0, 0) - toSeconds(0, 59, 59)},
                      SubParam{Time(0, 0, 30), Time(0, 0, 0), 0, 30}));

/* ===========================================================================
   Operator== Tests
   ===========================================================================
 */

struct CmpOpParam {
    Time lhs;
    Time rhs;
    int  rhs_seconds;
    bool expected;
};

class TimeEqualityTest : public ::testing::TestWithParam<CmpOpParam> {};

TEST_P(TimeEqualityTest, EqualityWithTime) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs == rhs, expected);
}

TEST_P(TimeEqualityTest, EqualityWithInt) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs == rhs_sec, expected);
}

INSTANTIATE_TEST_SUITE_P(
    EqualityOps, TimeEqualityTest,
    ::testing::Values(CmpOpParam{Time(1, 0, 0), Time(1, 0, 0), 3600, true},
                      CmpOpParam{Time(1, 0, 0), Time(0, 59, 59), 3599, false}));

/* ===========================================================================
   Operator!= Tests
   ===========================================================================
 */

class TimeInequalityTest : public ::testing::TestWithParam<CmpOpParam> {};

TEST_P(TimeInequalityTest, InequalityWithTime) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs != rhs, !expected);
}

TEST_P(TimeInequalityTest, InequalityWithInt) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs != rhs_sec, !expected);
}

INSTANTIATE_TEST_SUITE_P(
    InequalityOps, TimeInequalityTest,
    ::testing::Values(CmpOpParam{Time(1, 0, 0), Time(1, 0, 0), 3600, true},
                      CmpOpParam{Time(1, 0, 0), Time(0, 59, 59), 3599, false}));

/* ===========================================================================
   Operator< Tests
   ===========================================================================
 */

class TimeLessTest : public ::testing::TestWithParam<CmpOpParam> {};

TEST_P(TimeLessTest, LessThanTime) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs < rhs, expected);
}

TEST_P(TimeLessTest, LessThanInt) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs < rhs_sec, expected);
}

INSTANTIATE_TEST_SUITE_P(
    LessOps, TimeLessTest,
    ::testing::Values(CmpOpParam{Time(1, 0, 0), Time(2, 0, 0), 7200, true},
                      CmpOpParam{Time(1, 0, 0), Time(0, 59, 59), 3599, false}));

/* ===========================================================================
   Operator> Tests
   ===========================================================================
 */

class TimeGreaterTest : public ::testing::TestWithParam<CmpOpParam> {};

TEST_P(TimeGreaterTest, GreaterThanTime) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs > rhs, expected);
}

TEST_P(TimeGreaterTest, GreaterThanInt) {
    auto [lhs, rhs, rhs_sec, expected] = GetParam();
    EXPECT_EQ(lhs > rhs_sec, expected);
}

INSTANTIATE_TEST_SUITE_P(
    GreaterOps, TimeGreaterTest,
    ::testing::Values(CmpOpParam{Time(2, 0, 0), Time(1, 0, 0), 3600, true},
                      CmpOpParam{Time(1, 0, 0), Time(1, 0, 1), 3601, false}));

#endif  // TEST_TIME
