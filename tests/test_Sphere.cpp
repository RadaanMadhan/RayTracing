//
// Created by Radaa on 14/09/2025.
//
#include <gtest/gtest.h>
#include "geometry/Sphere.h"
#include "core/Ray.h"
#include "core/Vec3.h"

TEST(SphereTest, RayHitsSphere) {
    Sphere sphere(Vec3(0, 0, -5), 1.0f);
    Ray ray(Vec3(0, 0, 0), Vec3(0, 0, -1));
    HitRecord rec;

    bool hit = sphere.hit(ray, 0.001f, 100.0f, rec);

    EXPECT_TRUE(hit);
    EXPECT_NEAR(rec.t, 4.0f, 1e-4);
    EXPECT_NEAR(rec.point.z, -4.0f, 1e-4);
    EXPECT_NEAR(rec.normal.length(), 1.0f, 1e-4);
}

TEST(SphereTest, RayMissesSphere) {
    Sphere sphere(Vec3(0, 0, -5), 1.0f);
    Ray ray(Vec3(0, 0, 0), Vec3(0, 1, 0));
    HitRecord rec;

    bool hit = sphere.hit(ray, 0.001f, 100.0f, rec);

    EXPECT_FALSE(hit);
}

TEST(SphereTest, RayStartsInsideSphere) {
    Sphere sphere(Vec3(0, 0, -5), 2.0f);
    Ray ray(Vec3(0, 0, -5), Vec3(0, 0, 1));
    HitRecord rec;

    bool hit = sphere.hit(ray, 0.001f, 100.0f, rec);

    EXPECT_TRUE(hit);
    EXPECT_GT(rec.t, 0.001f);
}

TEST(SphereTest, RayTooCloseToHit) {
    Sphere sphere(Vec3(0, 0, -5), 1.0f);
    Ray ray(Vec3(0, 0, 0), Vec3(0, 0, -1));
    HitRecord rec;

    bool hit = sphere.hit(ray, 6.1f, 100.0f, rec);

    EXPECT_FALSE(hit);
}

TEST(SphereTest, RayHitsAtTwoPoints) {
    Sphere sphere(Vec3(0, 0, -5), 1.0f);
    Ray ray(Vec3(0, 0, -10), Vec3(0, 0, 1));
    HitRecord rec;

    bool hit = sphere.hit(ray, 0.001f, 100.0f, rec);

    EXPECT_TRUE(hit);
    EXPECT_NEAR(rec.t, 4.0f, 1e-4);
}
