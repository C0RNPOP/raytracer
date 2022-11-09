cmake_minimum_required(VERSION 3.14)
project(
    raytracer 
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

add_executable(
    raytracer 
    src/main.cpp
)

add_executable(
    raytracer_tests 
    src/test.cpp
)
target_link_libraries(
    raytracer_tests
    PRIVATE Catch2::Catch2WithMain
)
