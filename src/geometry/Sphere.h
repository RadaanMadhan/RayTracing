//
// Created by Radaa on 13/09/2025.
//

#ifndef SPHERE_H
#define SPHERE_H
#include "Hittable.h"


class Sphere final : public Hittable{
private:
    Vec3 center;
    float radius;
public:
    Sphere(Vec3 center, float radius);
    bool hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const override;
};



#endif //SPHERE_H
