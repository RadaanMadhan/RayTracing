//
// Created by Radaa on 13/09/2025.
//

#ifndef EMISSIVE_H
#define EMISSIVE_H

#include "materials/Material.h"


class Emissive : public Material {
private:
    Vec3 albedo = Vec3(0, 0, 0);
    Vec3 emitColor;
public:
    Emissive(Vec3 emitColor);
    bool scatter(const Ray &in, Vec3 &point, Vec3 &normal, Vec3 &attenuation, Ray &scattered) override;
    Vec3 emit() const override;
    Vec3 getAlbedo() const override;
};



#endif //EMISSIVE_H
