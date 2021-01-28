#pragma once
#include "Sample.h"
#include "Scene.h"

class Sampler
{
public:
	int curX = 1, curY = 1;
	bool getSample(Sample* sample);
};

