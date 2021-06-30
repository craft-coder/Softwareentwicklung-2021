#pragma once
#include "Ray.h"

namespace raytracer {
class Camera {
  public:
    Camera();

    Ray getRay(double u, double v) const;

  private:
    Point3 origin_;
    Point3 lowerLeftCorner_;
    Vec3 horizontal_;
    Vec3 vertical_;
};
} // namespace raytracer
