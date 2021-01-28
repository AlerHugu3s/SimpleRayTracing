#include "Ray.h"

Ray::Ray(glm::vec3 point, glm::vec3 dir)
{
	this->point = point;
	this->dir = glm::normalize(dir-point);
	this->t_min = 0.1;
	this->t_max = 5;
}

Ray::Ray()
{
}
