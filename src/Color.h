#pragma once
#include "Vec3.h"
#include <ostream>

namespace raytracer {

void writeColor(std::ostream& out, Color color, int samplesPerPixel);

} // namespace raytracer
