#include "gtest/gtest.h"
#include "Vec3.h"

TEST(Vec3, DefaultConstructor_XisZero) {
    raytracer::Vec3 vec{};

    double x = vec.x();
    EXPECT_NEAR(x, 0.0, 0.00001);
}

TEST(Vec3, DefaultConstructor_YisZero) {
    raytracer::Vec3 vec{};

    double y = vec.y();
    EXPECT_NEAR(y, 0.0, 0.00001);
}

TEST(Vec3, DefaultConstructor_ZisZero) {
    raytracer::Vec3 vec{};

    double z = vec.z();
    EXPECT_NEAR(z, 0.0, 0.00001);
}
