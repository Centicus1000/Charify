#include "charify/image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "charify/stb_image.h"

Image::Image(const char* file) :
data{ stbi_load(file, &w, &h, &c, 3) }
{
    if (!data)
        std::cerr << "File Error: file not found. " << file << std::endl;
}

Image::~Image()
{
    delete data;
}


// access pixel
Pixel Image::at(int x, int y, int z=0) const
{
    return data[(y * w + x) * c + z];
}

// calc gray scale
Pixel Image::gray(int x, int y) const
{
    int sum{ 0 };
    for (int i{0}; i<c; i++) sum += at(x,y,i);
    return static_cast<stbi_uc>(sum / c);
}

Pixel Image::at(float fx, float fy) const
{
    // mod inputs to avoid access errors
    fx = fmod(fx, w); fy = fmod(fy, h);
    
    int   ix{ static_cast<int>(fx) }; // ciel
    float rx{ fx - ix }; // reminder
    
    int   iy{ static_cast<int>(fy) }; // ciel
    float ry{ fy - iy }; // reminder
    
    return (1-rx)*(1-ry) * gray(  ix,   iy)
          +(1-rx)*   ry  * gray(  ix, 1+iy)
          +   rx *(1-ry) * gray(1+ix,   iy)
          +   rx *   ry  * gray(1+ix, 1+iy);
}

Pixel Image::minimum() const
{
    stbi_uc min{ 255 };
    for(int j{0}; j<h; j++){
        for (int i{0}; i<w; i++) {
            min = fmin(min, gray(i, j));
        }
    }
    return min;
}


Pixel Image::maximum() const
{
    stbi_uc max{ 0 };
    for(int j{h-1}; j>=0; j--){
        for (int i{0}; i<w; i++) {
            max = fmax(max, gray(i, j));
        }
    }
    return max;
}

