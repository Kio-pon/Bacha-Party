#ifndef TEST_MIXED_FRACTION
#define TEST_MIXED_FRACTION

#include <gtest/gtest.h>

#include <sstream>

#include "../src/MixedFraction.hpp"

// =======================
// Helper for comparing mixed fractions easily
// =======================
void ExpectEqual(const MixedFraction& a, const MixedFraction& b) {
    EXPECT_EQ(a.getWhole(), b.getWhole());
    EXPECT_EQ(a.getNumerator(), b.getNumerator());
    EXPECT_EQ(a.getDenominator(), b.getDenominator());
}

// =======================
// operator+
// =======================
struct AddTest : public ::testing::TestWithParam<
                     std::tuple<MixedFraction, MixedFraction, MixedFraction>> {
};
INSTANTIATE_TEST_SUITE_P(
    AdditionTests, AddTest,
    ::testing::Values(
        std::make_tuple(MixedFraction(1, 1, 2), MixedFraction(2, 1, 2),
                        MixedFraction(4, 0, 1)),  // 1.5 + 2.5 = 4
        std::make_tuple(MixedFraction(0, 3, 4), MixedFraction(0, 1, 4),
                        MixedFraction(1, 0, 1)),  // 0.75 + 0.25 = 1
        std::make_tuple(MixedFraction(2, 1, 3), MixedFraction(1, 2, 3),
                        MixedFraction(4, 0, 1))  // 2.333 + 1.667 = 4
        ));

TEST_P(AddTest, AdditionOperator) {
    auto [a, b, expected] = GetParam();
    MixedFraction result  = a + b;
    ExpectEqual(result, expected);
}

// =======================
// operator-
// =======================
struct SubtractTest
    : public ::testing::TestWithParam<
          std::tuple<MixedFraction, MixedFraction, MixedFraction>> {};

INSTANTIATE_TEST_SUITE_P(
    SubtractionTests, SubtractTest,
    ::testing::Values(
        std::make_tuple(MixedFraction(3, 1, 2), MixedFraction(1, 1, 2),
                        MixedFraction(2, 0, 1)),  // 3.5 - 1.5 = 2
        std::make_tuple(MixedFraction(1, 3, 4), MixedFraction(0, 1, 4),
                        MixedFraction(1, 1, 2)),  // 1.75 - 0.25 = 1.5
        std::make_tuple(MixedFraction(4, 0, 1), MixedFraction(1, 2, 4),
                        MixedFraction(2, 1, 2))  // 4 - 1.5 = 2.5
        ));

TEST_P(SubtractTest, SubtractionOperator) {
    auto [a, b, expected] = GetParam();
    MixedFraction result  = a - b;
    ExpectEqual(result, expected);
}

// =======================
// operator*
// =======================
struct MultiplicationTest
    : public ::testing::TestWithParam<
          std::tuple<MixedFraction, MixedFraction, MixedFraction>> {};
INSTANTIATE_TEST_SUITE_P(
    MultiplicationTests, MultiplicationTest,
    ::testing::Values(
        std::make_tuple(MixedFraction(1, 1, 2), MixedFraction(2, 0, 1),
                        MixedFraction(3, 0, 1)),  // 1.5 * 2 = 3
        std::make_tuple(MixedFraction(0, 3, 4), MixedFraction(0, 1, 2),
                        MixedFraction(0, 3, 8)),  // 0.75 * 0.5 = 0.375
        std::make_tuple(MixedFraction(2, 0, 1), MixedFraction(0, 1, 2),
                        MixedFraction(1, 0, 1))  // 2 * 0.5 = 1
        ));

TEST_P(MultiplicationTest, MultiplicationOperator) {
    auto [a, b, expected] = GetParam();
    MixedFraction result  = a * b;
    ExpectEqual(result, expected);
}

// =======================
// operator/
// =======================
struct DivisionTest
    : public ::testing::TestWithParam<
          std::tuple<MixedFraction, MixedFraction, MixedFraction>> {};
INSTANTIATE_TEST_SUITE_P(
    DivisionTests, DivisionTest,
    ::testing::Values(
        std::make_tuple(MixedFraction(3, 0, 1), MixedFraction(1, 1, 2),
                        MixedFraction(2, 0, 1)),  // 3 / 1.5 = 2
        std::make_tuple(MixedFraction(1, 1, 2), MixedFraction(0, 3, 4),
                        MixedFraction(2, 0, 1)),  // 1.5 / 0.75 = 2
        std::make_tuple(MixedFraction(2, 1, 2), MixedFraction(1, 1, 4),
                        MixedFraction(2, 0, 1))  // 2.5 / 1.25 = 2
        ));

TEST_P(DivisionTest, DivisionOperator) {
    auto [a, b, expected] = GetParam();
    MixedFraction result  = a / b;
    ExpectEqual(result, expected);
}

// =======================
// Compound operators
// =======================
TEST(MixedFractionCompoundTest, PlusEqualOperator) {
    MixedFraction a(1, 1, 2);  // 1.5
    MixedFraction b(0, 1, 2);  // 0.5
    a += b;                    // 2.0
    ExpectEqual(a, MixedFraction(2, 0, 1));
}

TEST(MixedFractionCompoundTest, MinusEqualOperator) {
    MixedFraction a(2, 1, 2);  // 2.5
    MixedFraction b(1, 1, 2);  // 1.5
    a -= b;                    // 1.0
    ExpectEqual(a, MixedFraction(1, 0, 1));
}

TEST(MixedFractionCompoundTest, TimesEqualOperator) {
    MixedFraction a(1, 0, 1);  // 1
    MixedFraction b(0, 3, 2);  // 1.5
    a *= b;                    // 1.5
    ExpectEqual(a, MixedFraction(1, 1, 2));
}

TEST(MixedFractionCompoundTest, DivideEqualOperator) {
    MixedFraction a(2, 0, 1);  // 2
    MixedFraction b(1, 0, 1);  // 1
    a /= b;                    // 2
    ExpectEqual(a, MixedFraction(2, 0, 1));
}

// =======================
// Comparison operators
// =======================
TEST(MixedFractionComparisonTest, EqualityOperator) {
    EXPECT_TRUE(MixedFraction(1, 1, 2) == MixedFraction(1, 1, 2));
    EXPECT_FALSE(MixedFraction(2, 0, 1) == MixedFraction(1, 1, 2));
}

TEST(MixedFractionComparisonTest, InequalityOperator) {
    EXPECT_TRUE(MixedFraction(2, 1, 3) != MixedFraction(1, 2, 3));
    EXPECT_FALSE(MixedFraction(3, 0, 1) != MixedFraction(3, 0, 1));
}

// =======================
// Normalization behavior
// =======================
TEST(MixedFractionNormalizationTest, ImproperToMixed) {
    MixedFraction mf(1, 5, 2);  // Should normalize to 3 1/2
    ExpectEqual(mf, MixedFraction(3, 1, 2));
}

#endif  // TEST_MIXED_FRACTION