//
// Created by Radaa on 13/09/2025.
//

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
public:
    Vec3 origin;
    Vec3 direction;
    Ray();
    Ray(Vec3 origin, Vec3 direction);
    [[nodiscard]] Vec3 at(float time) const;
};



#endif //RAY_H
