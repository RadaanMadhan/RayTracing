//
// Created by Radaa on 13/09/2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <core/Camera.h>
#include <render/Image.h>
#include <core/Vec3.h>
#include <geometry/HittableList.h>


class Renderer {
private:
    int width, height;
    int samplesPerPixel;
    int maxDepth;
    Vec3 backgroundColor;
public:
    Renderer(int width, int height, int samplesPerPixel, int maxDepth, const Vec3& backgroundColor);
    void renderCPU(const HittableList &world, const Camera &camera, Image &image, const std::string &outputFile) const;
    void renderGPU(const HittableList &world, const Camera &camera, Image &image, const std::string &outputFile) const;
};

Vec3 rayColor(const Ray& r, const Hittable& world, int depth, const Vec3& backgroundColor);

#endif //RENDERER_H
