#pragma once
#include<glm/glm.hpp>
class Ray
{
public:
	glm::vec3 point;
	glm::vec3 dir;
	float t,t_min, t_max;
	Ray(glm::vec3 point, glm::vec3 dir);
	Ray();
};

