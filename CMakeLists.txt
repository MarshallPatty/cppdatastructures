cmake_minimum_required(VERSION 3.10)

# set the project name
project(cppdatastructures)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the DataStructures library
add_subdirectory(DataStructures)
list(APPEND EXTRA_LIBS DataStructures)

# add the executable
add_executable(cppdatastructures main.cpp)

target_link_libraries(cppdatastructures PUBLIC ${EXTRA_LIBS})

target_include_directories(cppdatastructures PUBLIC "${PROJECT_BINARY_DIR}")
