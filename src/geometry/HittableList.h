//
// Created by Radaa on 14/09/2025.
//

#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include <memory>
#include <vector>
#include "Hittable.h"

class HittableList final : public Hittable{
public:
  std::vector<std::shared_ptr<Hittable>> objects;
  HittableList() = default;
  explicit HittableList(const std::vector<std::shared_ptr<Hittable>> &objects);
  void add(std::shared_ptr<Hittable> object);
  bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
};



#endif //HITTABLELIST_H
