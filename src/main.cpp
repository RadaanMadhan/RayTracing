#include <iostream>
#include <memory>
#include "core/Vec3.h"
#include "core/Ray.h"
#include "render/Renderer.h"
#include "render/Image.h"
#include "core/Camera.h"
#include "geometry/Sphere.h"
#include "geometry/HittableList.h"
#include "materials/Material.h"
#include "materials/Lambertian.h"
#include <cmath>
#include <materials/Emissive.h>

int main() {
    // Image
    constexpr int imageWidth = 800;
    constexpr int imageHeight = 400;
    constexpr int samplesPerPixel = 200;
    constexpr int maxDepth = 50;

    Image image(imageWidth, imageHeight);

    // Camera
    const Vec3 origin(0, 0, -5);
    const Vec3 lookAt(0, 0, 0.5);
    const Vec3 up(0, 1, 0);
    float fov = 40 * M_PI / 180; //in Radians
    float aspect = imageWidth / imageHeight;

    Camera camera(origin, lookAt, up, fov, aspect);

    //World
    HittableList world;

    //Objects
    auto whiteLight = std::make_shared<Emissive>(Vec3(10,10,10));
    auto blue = std::make_shared<Lambertian>(Vec3(0.02f, 0.03f, 0.08f));
    auto groundMaterial = std::make_shared<Lambertian>(Vec3(0.003f, 0.003f, 0.003f));

    world.add(std::make_shared<Sphere>(Vec3(0, 0, 0.5), 1.0f, blue));
    world.add(std::make_shared<Sphere>(Vec3(0, 5, -2), 1.0f, whiteLight));
    world.add(std::make_shared<Sphere>(
        Vec3(0, -1001.5f, 0),  // center far below origin
        1000.0f,                // huge radius
        groundMaterial
    ));

    // Renderer
    const Vec3 backgroundColor(0.0f, 0.0f, 0.0f);
    Renderer renderer(imageWidth, imageHeight, samplesPerPixel, maxDepth, backgroundColor);

    std::cout << "Begin render\n";
    renderer.render(world, camera, image, "render.ppm");
    std::cout << "Done\n";

    return 0;
}
