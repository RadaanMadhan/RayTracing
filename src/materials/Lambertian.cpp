//
// Created by Radaa on 13/09/2025.
//

#include "Lambertian.h"

#include <geometry/Hittable.h>

#include "utils/random.cpp"

bool Lambertian::scatter(const Ray& in, Vec3& point, Vec3& normal, Vec3& attenuation, Ray& scattered) {
    Vec3 scatterDirection = normal + randomUnitVec();
    if (scatterDirection.nearZero())
        scatterDirection = normal;
    scattered = Ray(point, scatterDirection);
    attenuation = this->albedo;
    return true;
}

Vec3 Lambertian::getAlbedo() const{
    return albedo;
}
