#pragma once

#include <iostream>
#include <cmath>

typedef unsigned char Pixel;

struct Image
{
    // attributes
    int w, h, c;
    Pixel* data;
    
    // constructor
    Image(const char* file);
    // destuctor
    ~Image();
    
    // access pixel
    Pixel at(int, int, int) const;
    Pixel gray(int, int) const;
    Pixel at(float, float) const;
    
    Pixel minimum() const;
    Pixel maximum() const;
};

