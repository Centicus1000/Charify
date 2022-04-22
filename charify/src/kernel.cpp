#include "charify/kernel.hpp"

Kernel SobelX()
{
    return
    {
        1.f, 0.f, -1.f,
        2.f, 0.f, -2.f,
        1.f, 0.f, -1.f
    };
}
Kernel SobelY()
{
    return
    {
        1.f, 2.f, 1.f,
        0.f, 0.f, 0.f,
        -1.f, -2.f, -1.f
    };
}


float conv(const Image& img, const Kernel& kernel, float xoff, float yoff)
{
    float result{ 0.f };
    for (int y{0}; y<k_height; y++) {
        float fy{ yoff + .5f - 2*(.5f*k_height + y) };
        
        for (int x{0}; x<k_width; x++) {
            float fx{ xoff + .5f - 2*(.5f*k_width + x) };
            
            float w { kernel[y*k_width + x] };
            result += w * img.at(fx, fy);
        }
    }
    return result;
}
