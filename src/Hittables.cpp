#include "Hittables.h"

namespace raytracer {

void Hittables::clear() {
    objects_.clear();
}

void Hittables::add(std::shared_ptr<Hittable> object) {
    objects_.push_back(object);
}

bool Hittables::hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const {
    HitRecord tempHitRecord;
    bool hitAnything = false;
    auto closestSoFar = tMax;

    for (const auto& object : objects_) {
        if (object->hit(ray, tMin, closestSoFar, tempHitRecord)) {
            hitAnything = true;
            closestSoFar = tempHitRecord.distance;
            hitRecord = tempHitRecord;
        }
    }

    return hitAnything;
}

} // namespace raytracer
