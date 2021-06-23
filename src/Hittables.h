#pragma once
#include "Hittable.h"
#include <vector>
#include <memory>

namespace raytracer {

class Hittables : public Hittable {
  public:
    void clear();
    void add(std::shared_ptr<Hittable> object);
    bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const override;

  private:
    std::vector<std::shared_ptr<Hittable>> objects_;
};

} // namespace raytracer
