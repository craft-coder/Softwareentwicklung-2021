#include "Color.h"
#include <algorithm>
#include <cmath>

namespace raytracer {

void writeColor(std::ostream& out, Color color, int samplesPerPixel) {
    auto r = color.x();
    auto g = color.y();
    auto b = color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samplesPerPixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    // Write the translated [0,255] value of each color component.
    auto red = static_cast<int>(255.999 * std::clamp(r, 0.0, 0.999));
    auto green = static_cast<int>(255.999 * std::clamp(g, 0.0, 0.999));
    auto blue = static_cast<int>(255.999 * std::clamp(b, 0.0, 0.999));

    out << red << ' ' << green << ' ' << blue << '\n';
}

} // namespace raytracer
