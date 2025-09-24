//
// Created by Radaa on 14/09/2025.
//
#include <stdlib.h>
#include <cmath>

#include "core/Vec3.h"

inline float randomFloat(const float min = 0, const float max = 1){
    //Random float from min to max. default [0, 1]
    return min + (max-min)*(static_cast<float>(rand())/static_cast<float>(RAND_MAX));
}

inline Vec3 randomInUnitSphere() {
    float u = randomFloat(); // [0,1)
    float v = randomFloat();
    float theta = 2.0f * M_PI * u;  // azimuth
    float phi = std::acos(2.0f * v - 1.0f); // inclination
    float r = std::cbrt(randomFloat()); // radius

    float x = r * std::sin(phi) * std::cos(theta);
    float y = r * std::sin(phi) * std::sin(theta);
    float z = r * std::cos(phi);

    return Vec3(x, y, z);
}

inline Vec3 randomUnitVec() {
    float u = randomFloat(); // [0,1)
    float v = randomFloat();
    float theta = 2.0f * M_PI * u;   // azimuth
    float phi = std::acos(2.0f * v - 1.0f); // inclination

    float x = std::sin(phi) * std::cos(theta);
    float y = std::sin(phi) * std::sin(theta);
    float z = std::cos(phi);

    return Vec3(x, y, z);
}

inline Vec3 randomCosineDirection() {
    float r1 = randomFloat();       // uniform [0,1)
    float r2 = randomFloat();       // uniform [0,1)

    float z = std::sqrt(1.0f - r2);       // cosine weighting
    float phi = 2.0f * M_PI * r1;
    float x = std::cos(phi) * std::sqrt(r2);
    float y = std::sin(phi) * std::sqrt(r2);

    return Vec3(x, y, z);
}