#include "PointLight.h"

PointLight::PointLight(float intensity, glm::vec3 center)
{
	this->intensity = intensity;
	this->vec = center;
	this->type = pointLight;
}
