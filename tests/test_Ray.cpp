#include "core/Vec3.h"
#include "core/Ray.h"
#include <gtest/gtest.h>

TEST(RayTest, DefaultConstructor) {
    Ray r;
    EXPECT_EQ(r.origin, Vec3(0, 0, 0));
    EXPECT_EQ(r.direction, Vec3(0, 0, 0));
}

TEST(RayTest, ParameterizedConstructor) {
    Vec3 o(1, 2, 3);
    Vec3 d(4, 5, 6);
    Ray r(o, d);

    EXPECT_EQ(r.origin, o);
    EXPECT_EQ(r.direction, d);
}

TEST(RayTest, AtMethodZero) {
    Vec3 o(1, 2, 3);
    Vec3 d(1, 0, 0);
    Ray r(o, d);

    Vec3 point = r.at(0.0f);
    EXPECT_EQ(point, o);
}

TEST(RayTest, AtMethodPositiveT) {
    Vec3 o(0, 0, 0);
    Vec3 d(1, 2, 3);
    Ray r(o, d);

    Vec3 point = r.at(2.0f);
    EXPECT_EQ(point, Vec3(2, 4, 6));
}

TEST(RayTest, AtMethodNegativeT) {
    Vec3 o(1, 1, 1);
    Vec3 d(0, 1, 0);
    Ray r(o, d);

    Vec3 point = r.at(-2.0f);
    EXPECT_EQ(point, Vec3(1, -1, 1));
}
