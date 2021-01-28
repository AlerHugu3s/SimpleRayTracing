#include "Film.h"

void Film::commit(Sample& sample, Color &color)
{
	sample.r = color.r;
	sample.g = color.g;
	sample.b = color.b;
	this->sample[sample.x][sample.y] = sample;
}

void Film::writeImage()
{
	std::ofstream outfile("mytest.ppm");
	outfile << "P3\n" << screenWitdh << " " << screenHeight << "\n255\n";
	for (int i = 1; i <= screenHeight; i++)
	{
		for (int j = 1; j <= screenWitdh; j++)
		{
			int ir = int(255.99 * sample[j][i].r);
			int ig = int(255.99 * sample[j][i].g);
			int ib = int(255.99 * sample[j][i].b);
			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}
}

Film::Film()
{

}
