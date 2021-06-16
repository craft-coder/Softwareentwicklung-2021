#pragma once
#include "Vec3.h"
#include "Ray.h"

namespace raytracer {

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double distance;
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const = 0;
};

} // namespace raytracer
