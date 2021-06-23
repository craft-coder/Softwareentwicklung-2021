#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"
#include "Hittables.h"
#include <iostream>
#include <thread>

using namespace raytracer;

Color background(const Ray& ray) {
    auto unitDirection = unitVector(ray.direction());
    auto t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

Color rayColor(const Ray& ray, Hittable& hittable) {
    HitRecord hitRecord;
    
    if (hittable.hit(ray, 0, 1000, hitRecord)) {
        return 0.5 * (hitRecord.normal + Color(1, 1, 1));
    }
    
    return background(ray);
}

int main() {

    // Image
    const auto aspectRation = 16.0 / 9.0;
    const int imageWidth = 400;
    const int imageHeigth = static_cast<int>(imageWidth / aspectRation);

    // Hittable Objects in our scene
    Hittables sceneObjects;
    
    auto sphere = std::make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    sceneObjects.add(sphere);

    // Camera
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRation * viewportHeight;
    auto focalLength = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Vec3(viewportWidth, 0, 0);
    auto vertical = Vec3(0, viewportHeight, 0);
    auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

    // Render
    std::cerr << "Starting rendering" << std::endl;
    std::cout << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int j = imageHeigth - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < imageWidth; ++i) {

            auto u = double(i) / (imageWidth - 1);
            auto v = double(j) / (imageHeigth - 1);

            auto direction = lowerLeftCorner + u * horizontal + v * vertical - origin;
            auto ray = Ray(origin, direction);

            auto color = rayColor(ray, sceneObjects);
            writeColor(std::cout, color);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}
