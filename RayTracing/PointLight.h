#pragma once
#include"Light.h"
class PointLight : public Light
{
public:
	PointLight(float intensity, glm::vec3 center);
};

