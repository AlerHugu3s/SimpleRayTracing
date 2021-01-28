#pragma once
#include<glm/glm.hpp>
#include"Ray.h"
class Sphere
{
public:
	float radius, shininess;
	glm::vec3 center, diffuse, specular;
	glm::vec3 intersect(Ray* ray, bool isLightDetect);
	Sphere(float radius, glm::vec3 center, glm::vec3 diffuse, glm::vec3 specular, float shininess);
	Sphere();
};

