//
// Created by Radaa on 13/09/2025.
//

#include "Camera.h"

#include <cmath>

Camera::Camera(const Vec3 origin, const Vec3 lookAt, const Vec3 up, const float fov, const float aspect) {
    this->origin = origin;
    this->forwardVector = (lookAt - origin).normalize();
    this->rightVector = forwardVector.cross(up).normalize();
    this->upVector = rightVector.cross(forwardVector).normalize();
    this->fov = fov;
    this->aspect = aspect;
    const float height = 2 * std::tan(fov / 2); //Setting d = 1
    const float width = aspect * height;
    this->horizontalSpan = rightVector * width;
    this->verticalSpan = upVector * height;
    this->lowerLeftCorner = origin + forwardVector - horizontalSpan / 2 - verticalSpan / 2; //Setting d = 1
}
Ray Camera::getRay(const float u, const float v) const {
    return {origin, (lowerLeftCorner + u * horizontalSpan + v * verticalSpan - origin).normalize()};
}
void Camera::setFov(const float fov) {
    const float height = 2 * std::tan(fov / 2);
    const float width = aspect * height;
    this->fov = fov;
    this->horizontalSpan = rightVector * width;
    this->verticalSpan = upVector * height;
    this->lowerLeftCorner = origin + forwardVector - horizontalSpan / 2 - verticalSpan / 2;
}
Vec3 Camera::getOrigin() const {
    return origin;
}
Vec3 Camera::getDirection() const {
    return forwardVector;
}
float Camera::getViewportHeight() const {
    return 2 * std::tan(this->fov / 2);
}
float Camera::getViewportWidth() const {
    return aspect * 2 * std::tan(this->fov / 2);
}

