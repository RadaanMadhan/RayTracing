//
// Created by Radaa on 13/09/2025.
//

#include "Vec3.h"

#include <cmath>
#include <valarray>

Vec3::Vec3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vec3::Vec3(const float x, const float y, const float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
float Vec3::length() const {
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
float Vec3::squaredLength() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}
Vec3 Vec3::normalize() const {
    float const length = this->length();
    return { this->x / length, this->y / length, this->z / length };
}
float Vec3::dot(const Vec3& other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}
Vec3 Vec3::cross(const Vec3& other) const {
    return {
        this->y * other.z - this->z * other.y,
        this->z * other.x - this->x * other.z,
        this->x * other.y - this->y * other.x
    };
}
Vec3 Vec3::operator+(const Vec3& other) const {
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}
Vec3 Vec3::operator+(const float other) const {
    return {this->x + other, this->y + other, this->z + other};
}
Vec3 Vec3::operator-(const Vec3& other) const {
    return {this->x - other.x, this->y - other.y, this->z - other.z};
}
Vec3 Vec3::operator-(const float other) const {
    return {this->x - other, this->y - other, this->z - other};
}
Vec3 Vec3::operator-() const {
    return {-this->x, -this->y, -this->z};
}
Vec3 Vec3::operator*(const Vec3 &other) const {
    return {this->x * other.x, this->y * other.y, this->z * other.z};
}
Vec3 Vec3::operator*(const float other) const {
    return {this->x * other, this->y * other, this->z * other};
}
Vec3 Vec3::operator/(const float other) const {
    return {this->x / other, this->y / other, this->z / other};
}
void Vec3::operator+=(const Vec3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
}
void Vec3::operator-=(const Vec3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
}
void Vec3::operator*=(const float other) {
    this->x *= other;
    this->y *= other;
    this->z *= other;
}
void Vec3::operator/=(const float other) {
    this->x /= other;
}
bool Vec3::operator==(const Vec3& other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}
Vec3 operator+(const float lhs, const Vec3& rhs) {
    return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z};
}
Vec3 operator-(const float lhs, const Vec3& rhs) {
    return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z};
}
Vec3 operator*(const float lhs, const Vec3& rhs) {
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
}
Vec3 operator/(const float lhs, const Vec3& rhs) {
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
}
bool Vec3::nearZero() const {
    constexpr float s = 1e-8f;
    return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
}

