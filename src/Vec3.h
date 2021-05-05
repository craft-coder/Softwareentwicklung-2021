#pragma once

namespace raytracer {

// This class represents a three-dimensional vector
class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double x, y, z;
};

} // namespace raytracer
