//
// Created by Radaa on 13/09/2025.
//

#include "Emissive.h"

Emissive::Emissive(Vec3 emitColor) {
    this->emitColor = emitColor;
}
bool Emissive::scatter(const Ray &in, Vec3 &point, Vec3 &normal, Vec3 &attenuation, Ray &scattered) {
    return false;
}
Vec3 Emissive::getAlbedo() const {
    return albedo;
}
Vec3 Emissive::emit() const {
    return emitColor;
}



