cmake_minimum_required (VERSION 3.16)

project(RaytracingExample VERSION 0.0.1)

add_subdirectory(submodules/googletest)
add_subdirectory(src)
add_subdirectory(test)

# check if Doxygen is installed
find_package(Doxygen REQUIRED)
add_custom_target(DoxygenDocumentation ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating documentation with Doxygen"
    VERBATIM)