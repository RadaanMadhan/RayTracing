//
// Created by Radaa on 16/09/2025.
//
#include <vector>
#include <cmath>
#include "core/Vec3.h"

// Create a Gaussian kernel
std::vector<std::vector<float>> createGaussianKernel(int kernelSize, float sigma) {
    std::vector<std::vector<float>> kernel(kernelSize, std::vector<float>(kernelSize));
    int half = kernelSize / 2;
    float sum = 0.0f;

    for (int y = -half; y <= half; ++y) {
        for (int x = -half; x <= half; ++x) {
            float value = std::exp(-(x*x + y*y) / (2.0f * sigma * sigma));
            kernel[y + half][x + half] = value;
            sum += value;
        }
    }

    // Normalize kernel so the sum is 1
    for (int y = 0; y < kernelSize; ++y)
        for (int x = 0; x < kernelSize; ++x)
            kernel[y][x] /= sum;

    return kernel;
}

// Apply Gaussian filter to a pixel buffer
void gaussianFilter(std::vector<Vec3>& pixels, int width, int height, int kernelSize = 5, float sigma = 1.0f) {
    auto kernel = createGaussianKernel(kernelSize, sigma);
    std::vector<Vec3> temp = pixels;
    int half = kernelSize / 2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Vec3 sum(0,0,0);

            for (int ky = -half; ky <= half; ++ky) {
                for (int kx = -half; kx <= half; ++kx) {
                    int nx = x + kx;
                    int ny = y + ky;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        sum += temp[ny * width + nx] * kernel[ky + half][kx + half];
                    }
                }
            }

            pixels[y * width + x] = sum;
        }
    }
}