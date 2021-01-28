#include "Sphere.h"

glm::vec3 Sphere::intersect(Ray* ray,bool isLightDetect)
{
	float a = glm::dot((*ray).dir, (*ray).dir);
	float b = 2 * glm::dot((*ray).dir, (*ray).point - center);
	float c = glm::dot((*ray).point - center, (*ray).point - center) - radius * radius;
	float delta = b * b - 4 * a * c;

	if (delta < 0)
	{
		return glm::vec3(0,0,0);
	}
	else if (delta == 0)
	{
		(*ray).t = -b / (2 * a);
		return (*ray).point + (*ray).t * (*ray).dir;
	}
	else
	{
		float t1 = ((-b + sqrt(delta)) / (2 * a));
		float t2 = ((-b - sqrt(delta)) / (2 * a));
		if (isLightDetect)
		{
			if (t1 < 0 && t2 < 0)return glm::vec3(0, 0, 0);
		}
		if (t2 < 0 && t1 >= 0) (*ray).t = t1;
		else if (t1 < 0 && t2 >= 0) (*ray).t = t2;
		else if( t1 >=0 && t2>=0)
		{
			if (t1 < t2) (*ray).t = t1;
			else (*ray).t = t2;
		}
		else return glm::vec3(0, 0, 0);
		return (*ray).point + (*ray).t * (*ray).dir;
	}
	return glm::vec3(0, 0, 0);
}

Sphere::Sphere(float radius, glm::vec3 center ,glm::vec3 diffuse, glm::vec3 specular, float shininess)
{
	this->radius = radius;
	this->center = center;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
}

Sphere::Sphere()
{
}
