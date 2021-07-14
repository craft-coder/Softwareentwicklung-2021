#pragma once
#include "Material.h"

namespace raytracer {
class Metal : public Material {
  public:
    Metal(const Color& color);

    bool scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const override;

  private:
    static Vec3 reflect(const Vec3& v, const Vec3& n);

    Color color_;
};
} // namespace raytracer