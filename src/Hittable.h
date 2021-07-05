#pragma once
#include "Ray.h"
#include "Vec3.h"
#include <memory>

namespace raytracer {

class Material; // Forward declaration

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double distance;
    std::shared_ptr<Material> material;
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const = 0;
};

} // namespace raytracer
