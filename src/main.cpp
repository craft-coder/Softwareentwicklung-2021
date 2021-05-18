#include "Vec3.h"
#include <iostream>
#include <thread>

using namespace raytracer;

void writeColor(std::ostream& out, Color color) {
    
    // Write the translated [0,255] value of each Color component.
    auto red = static_cast<int>(255.999 * color.x());
    auto green = static_cast<int>(255.999 * color.y());
    auto blue = static_cast<int>(255.999 * color.z());
    
    out << red << ' ' << green << ' ' << blue << '\n';
}

int main() {

    // Image
    const int imageWidth = 256;
    const int imageHeigth = 256;

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int j = imageHeigth - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            
            auto color = Color(double(i) / (imageWidth - 1), double(j) / (imageHeigth - 1), 0.25);
            writeColor(std::cout, color);
            
        }
    }
    std::cerr << "\nDone.\n";

    return 0;
}
