//
// Created by Radaa on 13/09/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "core/Ray.h"
#include "core/Vec3.h"

class Material {
private:
    Vec3 albedo;
public:
    virtual ~Material() = default;
    virtual bool scatter(const Ray& in, Vec3& point, Vec3& normal, Vec3& attenuation, Ray& scattered) = 0;
    virtual Vec3 emit() const {return Vec3(0, 0, 0);}
    virtual Vec3 getAlbedo() const = 0;
};
#endif //MATERIAL_H
