#include "Camera.h"
#include "Color.h"
#include "Hittables.h"
#include "Lambertian.h"
#include "Metal.h"
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

    if (hittable.hit(ray, 0.001, 1000, hitRecord)) {
        
        if (!hitRecord.material) {
            return Color(0, 0, 0);
        }

        Ray scattered;
        Color attenuation;
        
        auto isScattering = hitRecord.material->scatter(ray, hitRecord, attenuation, scattered);
        
        if (!isScattering) {
            return Color(0, 0, 0);
        }

        return attenuation * rayColor(scattered, hittable, depth - 1);
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

    // Materials
    auto red = std::make_shared<Lambertian>(Color(0.9, 0.1, 0.1));
    auto yellow = std::make_shared<Lambertian>(Color(0.9, 0.9, 0.1));
    auto blue = std::make_shared<Lambertian>(Color(0.0, 0.0, 0.9));
    auto metal = std::make_shared<Metal>(Color(0.8, 0.8, 0.8));
    auto materialFloor = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));

    // Hittable Objects in our scene
    Hittables sceneObjects;

    auto redSphere = std::make_shared<Sphere>(Point3(0, 0, -1), 0.5, red);
    auto yellowSphere = std::make_shared<Sphere>(Point3(1, 0, -1.5), 0.5, yellow);
    auto blueSphere = std::make_shared<Sphere>(Point3(-1, 0, -2), 0.5, blue);
    auto metalSphere = std::make_shared<Sphere>(Point3(2, 0, -1), 0.5, metal);
    sceneObjects.add(redSphere);
    sceneObjects.add(yellowSphere);
    sceneObjects.add(blueSphere);
    sceneObjects.add(metalSphere);

    auto floor = std::make_shared<Sphere>(Point3(0, -100.5, -1), 100, materialFloor);
    sceneObjects.add(floor);

    // Camera
    auto lookFrom = Point3(-1, 1, 1);
    auto lookAt = Point3(0, 0, -1);
    auto viewUp = Vec3(0, 1, 0);
    Camera camera(lookFrom, lookAt, viewUp, Degree(40), aspectRatio);

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
