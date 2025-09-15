//
// Created by Radaa on 14/09/2025.
//

#include "Image.h"

#include <fstream>
#include <cmath>
#include <algorithm>
#include <iostream>

Image::Image(const int w, const int h) {
    this->width = w;
    this->height = h;
    this->pixels = std::vector<Vec3>(this->width * this->height);
}
int Image::getWidth() const{
    return this->width;
}
int Image::getHeight() const {
    return this->height;
}
void Image::setPixel(int x, int y, const Vec3 &color) {
    pixels[y * width + x] = color;
}
Vec3 Image::getPixel(int x, int y) const {
    return pixels[y * width + x];
}
void Image::writePPM(const std::string &filename) const{
    std::ofstream out(filename);
    std::cout << "Writing " << filename << std::endl;
    out << "P3\n" << width << " " << height << "\n255\n";
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            Vec3 pixel = getPixel(x, y);
            //Gamma correction
            float r = std::sqrt(pixel.x);
            float g = std::sqrt(pixel.y);
            float b = std::sqrt(pixel.z);
            // Clamp to [0,1] and convert to [0,255]
            auto toInt = [](float c) { return static_cast<int>(256 * std::clamp(c, 0.0f, 0.999f)); };
            out << toInt(r) << " " << toInt(g) << " " << toInt(b) << "\n";
            //std::cout << toInt(r) << " " << toInt(g) << " " << toInt(b) << "\n";
        }
    }
    out.close();
    std::cout << "Finished writing " << filename << std::endl;
}

