#pragma once
#include <ostream>

namespace raytracer {

// This class represents a three-dimensional vector
class Vec3 {
  public:
    Vec3();
    Vec3(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);
    Vec3& operator+=(const Vec3& v);
    Vec3& operator*=(const double t);
    Vec3& operator/=(const double t);
    double length() const;
    double lengthSquared() const;

  private:
    double x_, y_, z_;
};

// Type aliases for Vec3
using Point3 = Vec3; // 3D point
using Color = Vec3;  // RGB color

// Vec3 Utility Functions
std::ostream& operator<<(std::ostream& out, const Vec3& v);
Vec3 operator+(const Vec3& u, const Vec3& v);
Vec3 operator-(const Vec3& u, const Vec3& v);
Vec3 operator*(const Vec3& u, const Vec3& v);
Vec3 operator*(double t, const Vec3& v);
Vec3 operator*(const Vec3& v, double t);
Vec3 operator/(Vec3 v, double t);
double dot(const Vec3& u, const Vec3& v);
Vec3 cross(const Vec3& u, const Vec3& v);
Vec3 unitVector(Vec3 v);

} // namespace raytracer
