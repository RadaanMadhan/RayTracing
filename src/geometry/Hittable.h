//
// Created by Radaa on 13/09/2025.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include "core/Vec3.h"
#include "core/Ray.h"

struct HitRecord {
    Vec3 point;
    Vec3 normal;
    float t{}; //Ray: origin + t*direction
    bool frontFace{};

    void setFaceNormal(const Ray& r, const Vec3& outwardNormal) {
        frontFace = r.direction.dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable {
public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
};

#endif //HITTABLE_H