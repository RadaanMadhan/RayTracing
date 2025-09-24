//
// Created by Radaa on 13/09/2025.
//

#include "Lambertian.h"

#include <geometry/Hittable.h>

#include "utils/random.cpp"

bool Lambertian::scatter(const Ray& in, Vec3& point, Vec3& normal, Vec3& attenuation, Ray& scattered) {
    // Build an orthonormal basis (normal = w)
    Vec3 w = normal;
    Vec3 a = (std::fabs(w.x) > 0.1f) ? Vec3(0,1,0) : Vec3(1,0,0);
    Vec3 v = w.cross(a).normalize();
    Vec3 u = w.cross(v);

    Vec3 dir = randomCosineDirection();
    // Transform dir to world space
    Vec3 scatterDirection = u * dir.x + v * dir.y + w * dir.z;

    scattered = Ray(point, scatterDirection);
    attenuation = this->albedo;
    return true;
}

Vec3 Lambertian::getAlbedo() const{
    return albedo;
}
