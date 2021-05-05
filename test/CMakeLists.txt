
add_executable(RaytracerTests Vec3Tests.cpp)

target_link_libraries(RaytracerTests    PRIVATE     RaytracerLib
                                                    gtest_main)
