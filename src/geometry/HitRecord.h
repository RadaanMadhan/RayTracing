//
// Created by Radaa on 14/09/2025.
//

#ifndef HITRECORD_H
#define HITRECORD_H

#include "materials/Material.h"
#include <memory>

struct HitRecord {
    Vec3 point;
    Vec3 normal;
    float t{}; //Ray: origin + t*direction
    bool frontFace{};
    std::shared_ptr<Material> material;

    void setFaceNormal(const Ray& r, const Vec3& outwardNormal) {
        frontFace = r.direction.dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

#endif //HITRECORD_H
