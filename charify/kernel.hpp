#pragma once

#include "charify/image.hpp"

#include <array>

const int k_width{ 3 };
const int k_height{ 3 };
typedef std::array<float, k_height*k_width> Kernel;


// Kernel constructors
Kernel SobelX();
Kernel SobelY();

// convolute kernel over image
float conv(const Image&, const Kernel&, float, float);
