#include <iostream>
#include "Vec3.h"

int main() {

    raytracer::Vec3 v1{};
    std::cout << "the content of v1 is: " << v1.getX() << "," << v1.getY() << "," << v1.getZ() << std::endl;
    
    raytracer::Vec3 v2(1.0, 2.0, 3.0);
    std::cout << "the content of v2 is: " << v2.getX() << "," << v2.getY() << "," << v2.getZ() << std::endl;

    return 0;
}
