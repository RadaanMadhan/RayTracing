//
// Created by Radaa on 13/09/2025.
//

#include "Ray.h"

Ray::Ray() {
    this->origin = {0, 0, 0};
    this->direction = {0, 0, 0};
}

Ray::Ray(const Vec3 origin, const Vec3 direction) {
    this->origin = origin;
    this->direction = direction;
}

Vec3 Ray::at(const float time) const {
    return origin + direction * time;
}

