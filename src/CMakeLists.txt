
add_library(RaytracerLib STATIC Vec3.cpp
                                Color.cpp
                                Ray.cpp)
target_include_directories(RaytracerLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(RaytracerExecutable main.cpp)
target_link_libraries(RaytracerExecutable PRIVATE RaytracerLib)