//
// Created by Radaa on 13/09/2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include "Vec3.h"
#include "Ray.h"

class Camera {
private:
  Vec3 origin;
  Vec3 forwardVector;
  Vec3 rightVector;
  Vec3 upVector;
  float fov; // in Radians
  float aspect;
  Vec3 horizontalSpan;
  Vec3 verticalSpan;
  Vec3 lowerLeftCorner;
public:
  Camera(Vec3 origin, Vec3 lookAt, Vec3 up, float fov, float aspect);
  [[nodiscard]] Ray getRay(float u, float v) const;
  void setFov(float fov);

  [[nodiscard]] Vec3 getOrigin() const;
  [[nodiscard]] Vec3 getDirection() const;
  [[nodiscard]] float getViewportHeight() const;
  [[nodiscard]] float getViewportWidth() const;
};

#endif //CAMERA_H
