#include "charify/kernel.hpp"

#include <iostream>

float lerp(float x, float imin, float imax, float omin, float omax)
{
    return (omax-omin) / (imax-imin) * (x-imin) + omin;
}


char p2c(Pixel p, Pixel min=0, Pixel max=255)
{
    p -= min;
    int T{ (max-min) / 4 };
    if  (p <   T) return '#';
    if  (p < 2*T) return '*';
    if  (p < 3*T) return '.';
    return ' ';
}

char edge(float angle)
{
    angle /= M_PI;
    angle += .625f;
    angle = fmod(fmod(angle, 1.)+1.f,1.f);
    if (angle < .25f) return '-';
    if (angle < .50f) return '\\';
    if (angle < .75f) return '|';
     return '/';
}

int main(int argc, char const *argv[])
{
    std::cout << "# of args = "<< argc << std::endl;

    for (int i{0}; i<argc; i++) {
        std::cout << i <<": "<< argv[i] << std::endl;
    }
    
    // load image
    Image img{ argv[1] };
    if (!img.data) return -1;
    
    Kernel Sx{ SobelX() }, Sy{ SobelY() };
    Pixel min{ img.minimum() }, max{ img.maximum() };
    
    const int w{90}, h{45};
    for(int j{0}; j<h; j++){
        float fy{ lerp(j, 0, h, 0, img.h) };
        for (int i{0}; i<w; i++) {
            float fx{ lerp(i, 0, w, 0, img.w) };

            // gradient
            float gx{ conv(img, Sx, fx, fy) };
            float gy{ conv(img, Sy, fx, fy) };
            
            // magnitude
            Pixel G{ static_cast<Pixel>(sqrt(gx*gx + gy*gy))};
            if (G > 150 )
            {
                // draw edge
                float angle{ atan2(gy, gx) };
                std::cout << edge(angle);
            }
            else
                std::cout << p2c(img.at(fx, fy), min, max);

        }
        std::cout << std::endl;
    }
    
	return 0;
}
