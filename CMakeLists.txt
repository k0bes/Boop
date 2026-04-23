cmake_minimum_required(VERSION 3.20)
project(ct CXX)

set(CMAKE_C_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(ct ${SOURCES})

target_include_directories(ct PRIVATE src)

target_link_libraries(ct PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)