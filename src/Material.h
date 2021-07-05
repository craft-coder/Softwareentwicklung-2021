#pragma once
#include "Ray.h"

namespace raytracer {
    
struct HitRecord; // Forward declaration

class Material {
  public:
    virtual bool scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const = 0;
};

} // namespace raytracer