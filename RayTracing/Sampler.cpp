#include "Sampler.h"

bool Sampler::getSample(Sample* sample)
{
	sample->x = curX;
	sample->y = curY;
	if (curY == screenHeight && curX == screenWitdh) return false;
	if (curX == screenWitdh)
	{
		curY += 1;
		curX = 0;
	}
	curX += 1;
    return true;
}
