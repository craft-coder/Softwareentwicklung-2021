#include "Vec3.h"

namespace raytracer {

Vec3::Vec3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vec3::Vec3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vec3::getX() const {
    return x;
}

double Vec3::getY() const {
    return y;
}

double Vec3::getZ() const {
    return z;
}

}