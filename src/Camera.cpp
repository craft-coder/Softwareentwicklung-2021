#include "Camera.h"
#include <cmath>

namespace raytracer {

Camera::Camera(Point3 lookFrom, Point3 lookAt, Vec3 viewUp, Degree verticalFieldOfView, double aspectRatio) {

    auto theta = degreesToRadians(verticalFieldOfView);
    auto h = std::tan(theta/2);
    auto viewportHeight = 2.0 * h;
    auto viewportWidth = aspectRatio * viewportHeight;
    
    auto w = unitVector(lookFrom - lookAt);
    auto u = unitVector(cross(viewUp, w));
    auto v = cross(w, u);

    origin_ = lookFrom;
    horizontal_ = viewportWidth * u;
    vertical_ = viewportHeight * v;
    lowerLeftCorner_ = origin_ - horizontal_/2 - vertical_/2 - w;
}

Ray Camera::getRay(double u, double v) const {
    auto direction = lowerLeftCorner_ + u * horizontal_ + v * vertical_ - origin_;
    auto ray = Ray(origin_, direction);

    return ray;
}

Radian Camera::degreesToRadians(Degree degrees) {
    return degrees * M_PI / 180.0;
}

} // namespace raytracer
