#include "Camera.h"
#include "Color.h"
#include "Hittables.h"
#include "Random.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"
#include <iostream>
#include <thread>

using namespace raytracer;

Vec3 randomInUnitSphere() {
    while (true) {
        auto p = Vec3::random(-1, 1);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}

Color background(const Ray& ray) {
    auto unitDirection = unitVector(ray.direction());
    auto t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

Color rayColor(const Ray& ray, Hittable& hittable, int depth) {
    HitRecord hitRecord;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0) {
        return Color(0, 0, 0);
    }

    if (hittable.hit(ray, 0, 1000, hitRecord)) {
        auto target = hitRecord.point + hitRecord.normal + randomInUnitSphere();
        auto direction = target - hitRecord.point;
        auto ray = Ray(hitRecord.point, direction);
        return 0.5 * rayColor(ray, hittable, depth - 1);
    }

    return background(ray);
}

int main() {

    // Image
    const auto aspectRatio = 16.0 / 9.0;
    const int imageWidth = 400;
    const int imageHeigth = static_cast<int>(imageWidth / aspectRatio);
    const int samplesPerPixel = 100;
    const int maxDepth = 50;

    // Hittable Objects in our scene
    Hittables sceneObjects;

    auto sphere = std::make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    sceneObjects.add(sphere);

    auto floor = std::make_shared<Sphere>(Point3(0, -100.5, -1), 100);
    sceneObjects.add(floor);

    // Camera
    Camera camera;

    // Render
    std::cerr << "Starting rendering" << std::endl;
    std::cout << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int j = imageHeigth - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < imageWidth; ++i) {

            Color pixelColor(0, 0, 0);
            for (auto sample = 0; sample < samplesPerPixel; sample++) {
                auto u = (i + randomDouble()) / (imageWidth - 1);
                auto v = (j + randomDouble()) / (imageHeigth - 1);
                auto ray = camera.getRay(u, v);

                pixelColor += rayColor(ray, sceneObjects, maxDepth);
            }
            writeColor(std::cout, pixelColor, samplesPerPixel);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}
