#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(float intensity, glm::vec3 direction)
{
	this->intensity = intensity;
	this->vec = glm::normalize(direction);
	this->type = directionLight;
}

