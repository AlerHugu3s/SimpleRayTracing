#pragma once
#include"Ray.h"
#include"Color.h"
#include"Sphere.h"
#include"Scene.h"


class Raytracer
{
	
public:	
	glm::vec3 trace(Ray& ray, int depth, Color* color);
};

