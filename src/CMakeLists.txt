file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/geometry/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/materials/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/render/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(raytracer_lib ${SOURCES})
target_link_libraries(raytracer_lib PRIVATE SFML::Graphics SFML::Window SFML::System)
target_include_directories(raytracer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(raytracer main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_lib)
