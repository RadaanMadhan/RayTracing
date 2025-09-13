//
// Created by Radaa on 13/09/2025.
//
#include <gtest/gtest.h>
#include "core/Vec3.h"

// Test vector addition
TEST(Vec3Test, Addition) {
    Vec3 a(1, 2, 3);
    Vec3 b(4, 5, 6);
    Vec3 result = a + b;
    EXPECT_FLOAT_EQ(result.x, 5);
    EXPECT_FLOAT_EQ(result.y, 7);
    EXPECT_FLOAT_EQ(result.z, 9);
}


// Test scalar multiplication (member)
TEST(Vec3Test, ScalarMultiplicationMember) {
    Vec3 v(1, 2, 3);
    Vec3 result = v * 2.0f;
    EXPECT_FLOAT_EQ(result.x, 2);
    EXPECT_FLOAT_EQ(result.y, 4);
    EXPECT_FLOAT_EQ(result.z, 6);
}


// Test scalar multiplication (non-member)
TEST(Vec3Test, ScalarMultiplicationNonMember) {
    Vec3 v(1, 2, 3);
    Vec3 result = 2.0f * v;
    EXPECT_FLOAT_EQ(result.x, 2);
    EXPECT_FLOAT_EQ(result.y, 4);
    EXPECT_FLOAT_EQ(result.z, 6);
}

// Test dot product
TEST(Vec3Test, DotProduct) {
    Vec3 a(1, 2, 3);
    Vec3 b(4, -5, 6);
    float result = a.dot(b);
    EXPECT_FLOAT_EQ(result, 12); // 1*4 + 2*-5 + 3*6
}

// Test cross product
TEST(Vec3Test, CrossProduct) {
    Vec3 a(1, 0, 0);
    Vec3 b(0, 1, 0);
    Vec3 result = a.cross(b);
    EXPECT_FLOAT_EQ(result.x, 0);
    EXPECT_FLOAT_EQ(result.y, 0);
    EXPECT_FLOAT_EQ(result.z, 1);
}

// Test normalization
TEST(Vec3Test, Normalize) {
    Vec3 v(3, 0, 4);
    Vec3 result = v.normalize();
    EXPECT_NEAR(result.x, 0.6, 1e-6);
    EXPECT_NEAR(result.y, 0.0, 1e-6);
    EXPECT_NEAR(result.z, 0.8, 1e-6);
}
