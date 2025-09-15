//
// Created by Radaa on 13/09/2025.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include "core/Vec3.h"
#include "core/Ray.h"
#include <memory>
#include "geometry/HitRecord.h"

class Hittable {
public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
};

#endif //HITTABLE_H