#pragma once
#include"Ray.h"
#include"Color.h"
#include"Sphere.h"
#include"Scene.h"


class Raytracer
{
	
public:	
	glm::vec3 trace(Ray& ray, int depth, Color* color);

	glm::vec3 LightCompute(glm::vec3 normalVec,glm::vec3 directionVec, glm::vec3 halfVec,glm::vec3 diffuse, glm::vec3 specular, float shininess, float intensity);
};

