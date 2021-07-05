#pragma once
#include "Ray.h"

namespace raytracer {

using Degree = double;
using Radian = double;

class Camera {
  public:
    Camera(Point3 lookFrom, Point3 lookAt, Vec3 viewUp,
    Degree verticalFieldOfView, double aspectRatio);

    Ray getRay(double u, double v) const;

  private:
    static Radian degreesToRadians(Degree degrees);

    Point3 origin_;
    Point3 lowerLeftCorner_;
    Vec3 horizontal_;
    Vec3 vertical_;
};
} // namespace raytracer
