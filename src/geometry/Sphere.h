//
// Created by Radaa on 13/09/2025.
//

#ifndef SPHERE_H
#define SPHERE_H
#include "Hittable.h"
#include "geometry/HitRecord.h"
#include "materials/Material.h"

class Sphere final : public Hittable{
private:
    Vec3 center;
    float radius;
    std::shared_ptr<Material> material;
public:
    Sphere(Vec3 center, float radius, const std::shared_ptr<Material> &material);
    bool hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const override;
};



#endif //SPHERE_H
