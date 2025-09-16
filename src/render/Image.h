//
// Created by Radaa on 14/09/2025.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "core/Vec3.h"

class Image {
private:
    int width;
    int height;
    std::vector<Vec3> pixels; // flattened

public:
    Image(int w, int h);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    void setPixel(int x, int y, const Vec3& color);
    [[nodiscard]] Vec3 getPixel(int x, int y) const;
    void writePPM(const std::string& filename) const;
    void filter(int kernelSize, float sigma);
};



#endif //IMAGE_H
