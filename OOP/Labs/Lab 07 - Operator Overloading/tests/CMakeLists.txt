cmake_minimum_required(VERSION 3.0)

set(TestMixedFraction MIXEDFRACTION)
set(TestTime TIME)
set(TestVector2D VECTOR2D)

set(CMAKE_BUILD_TYPE Release)

add_executable(${TestMixedFraction} test_MixedFraction.cpp)
add_executable(${TestTime} test_Time.cpp)
add_executable(${TestVector2D} test_Vector2D.cpp)

enable_testing()

foreach(test ${TestMixedFraction} ${TestTime} ${TestVector2D})
    target_link_libraries(
        ${test} PUBLIC
        gtest
        gtest_main
        Lab07
    )
    
    add_test(
        NAME ${test}
        COMMAND ${test}
    )
endforeach()