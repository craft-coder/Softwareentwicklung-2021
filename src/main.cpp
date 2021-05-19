#include "Vec3.h"
#include <iostream>
#include <thread>

using namespace raytracer;

int main() {

    // Image
    const int imageWidth = 256;
    const int imageHeigth = 256;

    // Render
    std::cerr << "Starting rendering" << std::endl;
    std::cout << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int j = imageHeigth - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
       
        for (int i = 0; i < imageWidth; ++i) {
            
            auto color = Color(double(i) / (imageWidth - 1), 1.0, 1.0);
            
            // Write the translated [0,255] value of each Color component.
            auto red = static_cast<int>(255.999 * color.x());
            auto green = static_cast<int>(255.999 * color.y());
            auto blue = static_cast<int>(255.999 * color.z());
            
            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cerr << "\nDone.\n";

    return 0;
}
