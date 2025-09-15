file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/geometry/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/materials/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/render/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
)

add_library(raytracer_lib ${SOURCES})
target_include_directories(raytracer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(raytracer main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_lib)
