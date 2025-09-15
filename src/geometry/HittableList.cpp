//
// Created by Radaa on 14/09/2025.
//

#include "HittableList.h"
#include <vector>
#include <memory>
#include "geometry/HitRecord.h"

HittableList::HittableList(const std::vector<std::shared_ptr<Hittable> > &objects) {
    this->objects = objects;
}
void HittableList::add(std::shared_ptr<Hittable> object) {
    this->objects.push_back(object);
}
bool HittableList::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    float closest_so_far = tMax;

    for (const auto& object : objects) {
        if (object->hit(r, tMin, closest_so_far, temp_rec)) {
            // Automatically changes tMax boundary to nearest found
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

