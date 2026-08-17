cmake_minimum_required(VERSION 3.0)

set(This Lab07)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE RELEASE)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(
    Headers
    src/MixedFraction.hpp
    src/Time.hpp
    src/Vector2D.hpp
)

set(
    Sources
    src/MixedFraction.cpp
    src/Time.cpp
    src/Vector2D.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)