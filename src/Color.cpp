#include "Color.h"

namespace raytracer {

void writeColor(std::ostream& out, Color color) {
    // Write the translated [0,255] value of each color component.
    auto red = static_cast<int>(255.999 * color.x());
    auto green = static_cast<int>(255.999 * color.y());
    auto blue = static_cast<int>(255.999 * color.z());

    out << red << ' ' << green << ' ' << blue << '\n';
}

} // namespace raytracer
