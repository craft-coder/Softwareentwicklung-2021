#include "Lambertian.h"
#include "Hittable.h"

namespace raytracer {

Lambertian::Lambertian(const Color& color)
    : color_(color) {
}

bool Lambertian::scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const {
    auto scatterDirection = hitRecord.normal + randomUnitVector();

      // Catch degenerate scatter direction
    if (scatterDirection.isNearZero()) {
        scatterDirection = hitRecord.normal;
    }

    scattered = Ray(hitRecord.point, scatterDirection);
    attenuation = color_;
    return true;
}

} // namespace raytracer