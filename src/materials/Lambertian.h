//
// Created by Radaa on 13/09/2025.
//

#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "materials/Material.h"

class Lambertian : public Material{
private:
    Vec3 albedo;
public:
    explicit Lambertian(const Vec3 albedo) : albedo(albedo){}
    bool scatter(const Ray& in, Vec3& point, Vec3& normal, Vec3& attenuation, Ray& scattered) override;
    Vec3 getAlbedo() const override;
};



#endif //LAMBERTIAN_H
