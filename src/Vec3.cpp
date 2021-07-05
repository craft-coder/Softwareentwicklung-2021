#include "Vec3.h"
#include "Random.h"
#include <cmath>
#include <stdexcept>

namespace raytracer {

Vec3::Vec3()
    : x_(0.0)
    , y_(0.0)
    , z_(0.0) {
}

Vec3::Vec3(double x, double y, double z)
    : x_(x)
    , y_(y)
    , z_(z) {
}

double Vec3::x() const {
    return x_;
}

double Vec3::y() const {
    return y_;
}

double Vec3::z() const {
    return z_;
}

Vec3 Vec3::operator-() const {
    return Vec3(-x_, -y_, -z_);
}
double Vec3::operator[](int i) const {
    switch (i) {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    }
    // We should never reach this
    throw std::runtime_error("Wrong index " + std::to_string(i));
}

double& Vec3::operator[](int i) {
    switch (i) {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    }
    // We should never reach this
    throw std::runtime_error("Wrong index " + std::to_string(i));
}

Vec3& Vec3::operator+=(const Vec3& v) {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

Vec3& Vec3::operator*=(const double t) {
    x_ *= t;
    y_ *= t;
    z_ *= t;
    return *this;
}

Vec3& Vec3::operator/=(const double t) {
    return *this *= 1 / t;
}

double Vec3::length() const {
    return std::sqrt(lengthSquared());
}

double Vec3::lengthSquared() const {
    return x_ * x_ + y_ * y_ + z_ * z_;
}

bool Vec3::isNearZero() const {
    const auto s = 1e-8;
    return (fabs(x_) < s) && (fabs(y_) < s) && (fabs(z_) < s);
}

Vec3 Vec3::random() {
    return Vec3(randomDouble(), randomDouble(), randomDouble());
}

Vec3 Vec3::random(double min, double max) {
    return Vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}

Vec3 randomInUnitSphere() {
    while (true) {
        auto p = Vec3::random(-1, 1);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}

Vec3 randomUnitVector() {
    return unitVector(randomInUnitSphere());
}

// Vec3 Utility Functions
std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

Vec3 operator+(const Vec3& u, const Vec3& v) {
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

Vec3 operator-(const Vec3& u, const Vec3& v) {
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

Vec3 operator*(const Vec3& v, double t) {
    return t * v;
}

Vec3 operator/(Vec3 v, double t) {
    return (1 / t) * v;
}

double dot(const Vec3& u, const Vec3& v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(), u.x() * v.y() - u.y() * v.x());
}

Vec3 unitVector(Vec3 v) {
    return v / v.length();
}

} // namespace raytracer