#include "Sphere.h"
#include <cmath>

namespace raytracer {

Sphere::Sphere(Point3 center, double radius, std::shared_ptr<Material> material)
    : center_(center)
    , radius_(radius)
    , material_(material) {
}

bool Sphere::hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const {
    Vec3 oc = ray.origin() - center_;
    auto a = ray.direction().lengthSquared();
    auto half_b = dot(oc, ray.direction());
    auto c = oc.lengthSquared() - radius_ * radius_;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    auto sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-half_b + sqrtd) / a;
        if (root < tMin || tMax < root) return false;
    }

    hitRecord.distance = root;
    hitRecord.point = ray.at(hitRecord.distance);
    hitRecord.normal = (hitRecord.point - center_) / radius_;
    hitRecord.material = material_;

    return true;
}

} // namespace raytracer
