//
// Created by Radaa on 13/09/2025.
//

#include "Renderer.h"

#include <iostream>

#include "utils/random.cpp"
#include <limits>
#include <materials/Material.h>

Renderer::Renderer(const int width, const int height, const int samplesPerPixel, const int maxDepth, const Vec3& backgroundColor) {
    this->width = width;
    this->height = height;
    this->samplesPerPixel = samplesPerPixel;
    this->maxDepth = maxDepth;
    this->backgroundColor = backgroundColor;
}

void Renderer::render(const HittableList& world, const Camera& camera, Image& image, const std::string &outputFile) const {
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            Vec3 color(0,0,0);
            for (int s = 0; s < samplesPerPixel; ++s) {
                const float u = (i + randomFloat()) / width;
                const float v = (j + randomFloat()) / height;
                Ray r = camera.getRay(u, v);
                color += rayColor(r, world, maxDepth, backgroundColor);
            }
            color /= samplesPerPixel;

            //gamma correction
            color = Vec3(sqrt(color.x), sqrt(color.y), sqrt(color.z));

            image.setPixel(i, j, color);
        }
    }
    image.writePPM(outputFile);
}

Vec3 rayColor(const Ray &r, const Hittable &world, const int depth, const Vec3& backgroundColor) {

    if (depth <= 0) return Vec3(0,0,0);
    if (HitRecord rec; world.hit(r, 0.001f, std::numeric_limits<float>::infinity(), rec)) {
        Vec3 emitted = rec.material->emit();
        Vec3 attenuation;
        Ray scattered;
        if (rec.material->scatter(r, rec.point, rec.normal, attenuation, scattered))
            return emitted + attenuation * rayColor(scattered, world, depth-1, backgroundColor);
        return emitted;
    }
    // Black Background
    return Vec3(0,0,0);

    /*
    // Sky Gradient Background
    const Vec3 unitDir = r.direction.normalize();
    const float t = 0.5f * (unitDir.y + 1.0f);
    return (1.0 - t) * Vec3(1,1,1) + t * Vec3(0.5, 0.7, 1.0);
    */

}
