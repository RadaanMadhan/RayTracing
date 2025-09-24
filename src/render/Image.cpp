//
// Created by Radaa on 14/09/2025.
//

#include "Image.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "utils/filter.cpp"

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
void Image::setPixel(const int x, const int y, const Vec3 &color) {
    pixels[y * width + x] = color;
}
Vec3 Image::getPixel(const int x, const int y) const {
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
void Image::filter(const int kernelSize, const float sigma) {
    gaussianFilter(this->pixels, this->width, this->height, kernelSize, sigma);
}

void Image::displayImage() {
    // Create an SFML image
    sf::Image image({width, height});
    // Copy your framebuffer pixels into the SFML image
    for (int y = 0; y < height; y++) {
        for (unsigned x = 0; x < width; x++) {
            Vec3 c = pixels[y * width + x];

            // clamp color to [0, 1]
            float r = std::min(1.0f, std::max(0.0f, c.x));
            float g = std::min(1.0f, std::max(0.0f, c.y));
            float b = std::min(1.0f, std::max(0.0f, c.z));

            // apply gamma correction (linear to sRGB)
            r = std::pow(r, 1.0f / 2.2f);
            g = std::pow(g, 1.0f / 2.2f);
            b = std::pow(b, 1.0f / 2.2f);

            // convert to 0–255
            sf::Color pixel(
                static_cast<std::uint8_t>(r * 255),
                static_cast<std::uint8_t>(g * 255),
                static_cast<std::uint8_t>(b * 255)
            );

            image.setPixel({x, static_cast<unsigned>(height - 1 - y)}, pixel);
            // flip Y since SFML expects top-left origin
        }
    }

    // Put image into a texture and display it
    sf::Texture texture;
    if (!texture.loadFromImage(image)) {
        // Handle texture loading failure
        return;
    }

    sf::Sprite sprite(texture);

    sf::VideoMode video_mode({width, height});
    sf::RenderWindow window(video_mode, "Ray Tracer Output");

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
