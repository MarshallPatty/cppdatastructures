cmake_minimum_required(VERSION 3.10)

# set the project name
project(cppdatastructures)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
