enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")

add_executable(Vec3_tests test_Vec3.cpp)
add_executable(Ray_tests test_Ray.cpp)
add_executable(Camera_tests test_Camera.cpp)

target_link_libraries(Vec3_tests PRIVATE raytracer_lib gtest gtest_main)
target_link_libraries(Ray_tests PRIVATE raytracer_lib gtest gtest_main)
target_link_libraries(Camera_tests PRIVATE raytracer_lib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(Vec3_tests)
gtest_discover_tests(Ray_tests)
gtest_discover_tests(Camera_tests)