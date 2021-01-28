#pragma once
#include<glm/glm.hpp>

enum LightType
{
	pointLight = 0,
	directionLight = 1
};
class Light
{
private:
	
public:
	float intensity;
	glm::vec3 vec;
	Light();
	int GetType();
	glm::vec3 GetVec();
	int type;
};

