#include "Vec3.h"
#include <iostream>
#include <thread>

int main() {

    // Image
    const int imageWidth = 256;
    const int imageHeigth = 256;

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int j = imageHeigth - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            auto r = double(i) / (imageWidth - 1);
            auto g = double(j) / (imageHeigth - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cerr << "\nDone.\n";

    return 0;
}
