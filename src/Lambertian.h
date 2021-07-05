#pragma once
#include "Material.h"

namespace raytracer {
class Lambertian : public Material {
  public:
    Lambertian(const Color& color);

    bool scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const override;

  private:
    Color color_;
};
} // namespace raytracer