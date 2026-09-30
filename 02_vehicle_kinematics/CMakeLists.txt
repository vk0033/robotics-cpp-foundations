cmake_minimum_required(VERSION 3.16)

project(vehicle_kinematics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vehicle_sim
    src/main.cpp
    src/Vehicle.cpp
)

target_include_directories(vehicle_sim
    PRIVATE
        include
)

# -------------------------
# Testing
# -------------------------

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(vehicle_tests
    tests/test_vehicle.cpp
    src/Vehicle.cpp
)

target_include_directories(vehicle_tests
    PRIVATE
        include
)

target_link_libraries(vehicle_tests
    PRIVATE
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(vehicle_tests)