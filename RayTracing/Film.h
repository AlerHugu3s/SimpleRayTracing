#pragma once
#include"Sampler.h"
#include <fstream>

class Film
{
private:
    Sample sample[1000][1000];
public:
    
    // Will write the color to (sample.x, sample.y) on the image
    void commit(Sample& sample, Color& color);
    // Output image to a file
    void writeImage();
    Film();
};

