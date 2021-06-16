#pragma once
#include "Hittable.h"

namespace raytracer {

class Sphere : public Hittable {
  public:
    Sphere() = default;
    Sphere(Point3 center, double radius);

    bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const override;

  private:
    Point3 center_;
    double radius_;
};

} // namespace raytracer
