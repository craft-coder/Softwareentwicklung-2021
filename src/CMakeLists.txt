
add_library(RaytracerLib STATIC Vec3.cpp
                                Color.cpp
                                Ray.cpp
                                Sphere.cpp
                                Hittables.cpp
                                Random.cpp
                                Camera.cpp
                                Lambertian.cpp)
target_include_directories(RaytracerLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(RaytracerLib PROPERTIES CXX_STANDARD 17)

add_executable(RaytracerExecutable main.cpp)
target_link_libraries(RaytracerExecutable PRIVATE RaytracerLib)