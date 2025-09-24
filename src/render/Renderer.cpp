//
// Created by Radaa on 13/09/2025.
//

#include "Renderer.h"

#include <iostream>

#include <limits>
#include <thread>
#include <materials/Material.h>
#include <utils/random.cpp>

Renderer::Renderer(const int width, const int height, const int samplesPerPixel, const int maxDepth, const Vec3& backgroundColor) {
    this->width = width;
    this->height = height;
    this->samplesPerPixel = samplesPerPixel;
    this->maxDepth = maxDepth;
    this->backgroundColor = backgroundColor;
}

void Renderer::renderCPU(const HittableList& world, const Camera& camera, Image& image, const std::string &outputFile) const {
    const int tileSize = 32; // size of each tile in pixels
    const int tilesX = (width + tileSize - 1) / tileSize;
    const int tilesY = (height + tileSize - 1) / tileSize;

    std::atomic<int> nextTile(0);

    auto worker = [&]() {
        int tileIndex;
        while ((tileIndex = nextTile++) < tilesX * tilesY) {
            int tileX = tileIndex % tilesX;
            int tileY = tileIndex / tilesX;

            int xStart = tileX * tileSize;
            int yStart = tileY * tileSize;
            int xEnd = std::min(xStart + tileSize, width);
            int yEnd = std::min(yStart + tileSize, height);

            // Stratified sampling setup
            int sqrtSamples = std::ceil(std::sqrt(samplesPerPixel));
            float invSqrtSamples = 1.0f / sqrtSamples;

            for (int j = yStart; j < yEnd; ++j) {
                for (int i = xStart; i < xEnd; ++i) {
                    Vec3 color(0, 0, 0);
                    for (int sx = 0; sx < sqrtSamples; ++sx) {
                        for (int sy = 0; sy < sqrtSamples; ++sy) {
                            // Jittered stratified sampling
                            float u = (i + (sx + randomFloat()) * invSqrtSamples) / width;
                            float v = (j + (sy + randomFloat()) * invSqrtSamples) / height;

                            Ray r = camera.getRay(u, v);
                            color += rayColor(r, world, maxDepth, backgroundColor);
                        }
                    }
                    color /= float(samplesPerPixel);
                    image.setPixel(i, j, color);
                }
            }
        }
    };

    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    for (int t = 0; t < numThreads; ++t)
        threads.emplace_back(worker);

    for (auto &thread : threads)
        thread.join();

    image.filter(3, 1.0f);
    image.writePPM(outputFile);
    image.displayImage();
}

Vec3 rayColor(const Ray &r, const Hittable &world, const int depth, const Vec3& backgroundColor) {

    if (depth <= 0) return {0,0,0};
    if (HitRecord rec; world.hit(r, 0.001f, std::numeric_limits<float>::infinity(), rec)) {
        Vec3 emitted = rec.material->emit();
        Vec3 attenuation;
        Ray scattered;
        if (rec.material->scatter(r, rec.point, rec.normal, attenuation, scattered))
            return emitted + attenuation * rayColor(scattered, world, depth-1, backgroundColor);
        return emitted;
    }
    // Plain Background
    return backgroundColor;

    /*
    // Sky Gradient Background
    const Vec3 unitDir = r.direction.normalize();
    const float t = 0.5f * (unitDir.y + 1.0f);
    return (1.0 - t) * Vec3(1,1,1) + t * Vec3(0.5, 0.7, 1.0);
    */
}
