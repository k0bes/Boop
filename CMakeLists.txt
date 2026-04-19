cmake_minimum_required(VERSION 3.20)
project(ct CXX)

set(CMAKE_C_STANDARD 17)

find_package(SDL3 REQUIRED CONFIG)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(ct ${SOURCES})

# SDL3
target_link_libraries(ct PRIVATE SDL3::SDL3)

target_include_directories(ct PRIVATE src)