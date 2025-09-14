//
// Created by Radaa on 13/09/2025.
//

#include "Sphere.h"

#include <cmath>

Sphere::Sphere(const Vec3 center, const float radius) {
    this->center = center;
    this->radius = radius;
}
bool Sphere::hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const {
    Vec3 oc = r.origin - center;

    float a = r.direction.dot(r.direction);
    float b = 2.0f * oc.dot(r.direction);
    float c = oc.dot(oc) - radius * radius;

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }

    float sqrtD = std::sqrt(discriminant);

    // Find the nearest root in range
    float root = (-b - sqrtD) / (2.0f * a);
    if (root < t_min || root > t_max) {
        root = (-b + sqrtD) / (2.0f * a);
        if (root < t_min || root > t_max) {
            return false;
        }
    }

    rec.t = root;
    rec.point = r.at(root);
    rec.normal = (rec.point - center) / radius;

    return true;
}
