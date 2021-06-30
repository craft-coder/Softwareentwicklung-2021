#include "Random.h"
#include <random>

namespace raytracer {

double randomDouble() {
    return randomDouble(0.0, 1.0);
}

double randomDouble(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

} // namespace raytracer
