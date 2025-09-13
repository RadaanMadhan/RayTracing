//
// Created by Radaa on 13/09/2025.
//

#ifndef VEC3_H
#define VEC3_H



class Vec3 {
public:
  float x, y, z;

  Vec3();
  Vec3(float x, float y, float z);
  [[nodiscard]] float length() const;
  [[nodiscard]] float squaredLength() const;
  [[nodiscard]] Vec3 normalize() const;
  [[nodiscard]] float dot(const Vec3 &other) const;
  [[nodiscard]] Vec3 cross(const Vec3 &other) const;

  Vec3 operator+(const Vec3 &other) const;
  Vec3 operator+(float other) const;
  Vec3 operator-(const Vec3 &other) const;
  Vec3 operator-(float other) const;
  Vec3 operator*(float other) const;
  Vec3 operator/(float other) const;
  void operator+=(const Vec3& rhs);
  void operator-=(const Vec3& rhs);
  void operator*=(float other);
  void operator/=(float other);
  bool operator==(const Vec3& other) const;
};

Vec3 operator+(float lhs, const Vec3& rhs);
Vec3 operator-( float lhs, const Vec3& rhs);
Vec3 operator*(float lhs, const Vec3& rhs);
Vec3 operator/( float lhs, const Vec3& rhs);
#endif //VEC3_H
