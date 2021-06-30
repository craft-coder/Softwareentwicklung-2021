#include "Camera.h"

namespace raytracer {

Camera::Camera() {
    const auto aspectRation = 16.0 / 9.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRation * viewportHeight;
    auto focalLength = 1.0;

    origin_ = Point3(0, 0, 0);
    horizontal_ = Vec3(viewportWidth, 0, 0);
    vertical_ = Vec3(0, viewportHeight, 0);
    lowerLeftCorner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - Vec3(0, 0, focalLength);
}

Ray Camera::getRay(double u, double v) const {
    auto direction = lowerLeftCorner_ + u * horizontal_ + v * vertical_ - origin_;
    auto ray = Ray(origin_, direction);
    
    return ray;
}

} // namespace raytracer
