#ifndef TEST_VECTOR2D
#define TEST_VECTOR2D

#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>

#include "../src/Vector2D.hpp"

// =======================
// Fixture for parameterized tests
// =======================
struct Vector2DTest
    : public ::testing::TestWithParam<std::tuple<Vector2D, Vector2D, double>> {
};

auto v1sv2sdots =
    ::testing::Values(std::make_tuple(Vector2D(1, 2), Vector2D(3, 4), 11.0),
                      std::make_tuple(Vector2D(-1, 2), Vector2D(1, -2), -5.0),
                      std::make_tuple(Vector2D(0, 0), Vector2D(5, 6), 0.0));

INSTANTIATE_TEST_SUITE_P(, Vector2DTest, v1sv2sdots);
// =======================
// operator+
// =======================
TEST_P(Vector2DTest, AdditionOperator) {
    auto [v1, v2, _] = GetParam();
    Vector2D result  = v1 + v2;

    EXPECT_DOUBLE_EQ(result[0], v1[0] + v2[0]);
    EXPECT_DOUBLE_EQ(result[1], v1[1] + v2[1]);
}

// =======================
// operator-
// =======================
TEST_P(Vector2DTest, SubtractionOperator) {
    auto [v1, v2, _] = GetParam();
    Vector2D result  = v1 - v2;

    EXPECT_DOUBLE_EQ(result[0], v1[0] - v2[0]);
    EXPECT_DOUBLE_EQ(result[1], v1[1] - v2[1]);
}

// =======================
// operator* (scalar)
// =======================
TEST(Vector2DScalarTest, MultiplyByScalar) {
    Vector2D v(2.0, 3.0);
    double   scalar = 2.5;
    Vector2D result = v * scalar;

    EXPECT_DOUBLE_EQ(result[0], 5.0);
    EXPECT_DOUBLE_EQ(result[1], 7.5);
}

// =======================
// operator* (dot product)
// =======================
TEST_P(Vector2DTest, DotProductOperator) {
    auto [v1, v2, expectedDot] = GetParam();
    EXPECT_DOUBLE_EQ(v1 * v2, expectedDot);
}

// =======================
// Compound operators
// =======================
TEST(Vector2DCompoundTest, PlusEqualOperator) {
    Vector2D v1(1, 1);
    Vector2D v2(2, 3);
    v1 += v2;
    EXPECT_DOUBLE_EQ(v1[0], 3.0);
    EXPECT_DOUBLE_EQ(v1[1], 4.0);
}

TEST(Vector2DCompoundTest, MinusEqualOperator) {
    Vector2D v1(5, 5);
    Vector2D v2(2, 3);
    v1 -= v2;
    EXPECT_DOUBLE_EQ(v1[0], 3.0);
    EXPECT_DOUBLE_EQ(v1[1], 2.0);
}

TEST(Vector2DCompoundTest, TimesEqualOperator) {
    Vector2D v(3, 4);
    v *= 2;
    EXPECT_DOUBLE_EQ(v[0], 6.0);
    EXPECT_DOUBLE_EQ(v[1], 8.0);
}

// =======================
// Comparison operators
// =======================
TEST(Vector2DComparisonTest, EqualityOperator) {
    EXPECT_TRUE(Vector2D(1.0, 2.0) == Vector2D(1.0, 2.0));
    EXPECT_FALSE(Vector2D(1.0, 2.0) == Vector2D(2.0, 1.0));
}

TEST(Vector2DComparisonTest, InequalityOperator) {
    EXPECT_TRUE(Vector2D(1.0, 2.0) != Vector2D(2.0, 1.0));
    EXPECT_FALSE(Vector2D(1.0, 2.0) != Vector2D(1.0, 2.0));
}

// =======================
// Index operator
// =======================
TEST(Vector2DIndexTest, ValidIndices) {
    Vector2D v(3.5, 7.5);
    EXPECT_DOUBLE_EQ(v[0], 3.5);
    EXPECT_DOUBLE_EQ(v[1], 7.5);
}

#endif  // TEST_VECTOR2D