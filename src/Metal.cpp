#include "Metal.h"
#include "Hittable.h"

namespace raytracer {

Metal::Metal(const Color& color)
    : color_(color) {
}


bool Metal::scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const {
    
    auto reflectedDirection = reflect(unitVector(in.direction()), hitRecord.normal);
    scattered = Ray(hitRecord.point, reflectedDirection);
    attenuation = color_;

    return (dot(scattered.direction(), hitRecord.normal) > 0);
}

Vec3 Metal::reflect(const Vec3& v, const Vec3& n) {
    return v - 2*dot(v,n)*n;
}

} // namespace raytracer