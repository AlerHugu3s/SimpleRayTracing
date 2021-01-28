#pragma once
#include<glm/glm.hpp>
#include"Sample.h"
#include"Ray.h"

extern glm::vec3 eyePos;
class Camera
{
public:
	
	Camera(glm::vec3 eyePos);
	void GenerateRay(Sample &sample, Ray *ray);
	glm::vec3 xVec,yVec;
	glm::vec3 upVec;
};

