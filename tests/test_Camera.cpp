//
// Created by Radaa on 13/09/2025.
//
#include "core/Camera.h"
#include "core/Vec3.h"
#include <gtest/gtest.h>
#include <cmath>

// Helper for floating-point comparisons
inline bool nearlyEqual(float a, float b, float eps = 1e-5f) {
    return std::fabs(a - b) < eps;
}

TEST(CameraTest, StoresOriginAndDirection) {
    Vec3 origin(0, 0, 0);
    Vec3 lookAt(0, 0, -1);
    Vec3 up(0, 1, 0);
    Camera cam(origin, lookAt, up, 90.0f, 16.0f/9.0f);

    EXPECT_EQ(cam.getOrigin(), origin);

    Vec3 dir = cam.getDirection();
    EXPECT_TRUE(nearlyEqual(dir.length(), 1.0f));  // normalized
    EXPECT_TRUE(nearlyEqual(dir.z, -1.0f));        // facing -z
}

TEST(CameraTest, ViewportDimensionsMatchAspect) {
    Vec3 origin(0, 0, 0);
    Vec3 lookAt(0, 0, -1);
    Vec3 up(0, 1, 0);
    Camera cam(origin, lookAt, up, 90.0f, 16.0f/9.0f);

    float h = cam.getViewportHeight();
    float w = cam.getViewportWidth();

    EXPECT_TRUE(nearlyEqual(w / h, 16.0f/9.0f));
}

TEST(CameraTest, CenterRayPointsForward) {
    Vec3 origin(0, 0, 0);
    Vec3 lookAt(0, 0, -1);
    Vec3 up(0, 1, 0);
    Camera cam(origin, lookAt, up, 90.0f, 1.0f);

    Ray r = cam.getRay(0.5f, 0.5f);

    Vec3 dir = r.direction.normalize();
    EXPECT_TRUE(nearlyEqual(dir.dot(cam.getDirection()), 1.0f));  // almost parallel
    EXPECT_EQ(r.origin, origin);
}

TEST(CameraTest, RaysOriginAtCameraOrigin) {
    Vec3 origin(1, 2, 3);
    Vec3 lookAt(0, 0, -1);
    Vec3 up(0, 1, 0);
    Camera cam(origin, lookAt, up, 60.0f, 1.0f);

    Ray r = cam.getRay(0.2f, 0.8f);
    EXPECT_EQ(r.origin, origin);
}

TEST(CameraTest, ChangingFovUpdatesViewport) {
    Vec3 origin(0, 0, 0);
    Vec3 lookAt(0, 0, -1);
    Vec3 up(0, 1, 0);
    Camera cam(origin, lookAt, up, 45.0f, 1.0f);

    float oldH = cam.getViewportHeight();
    cam.setFov(90.0f);
    float newH = cam.getViewportHeight();

    EXPECT_GT(newH, oldH);  // bigger FOV = larger viewport
}