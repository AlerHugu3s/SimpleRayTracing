#include "Light.h"

Light::Light()
{
}

int Light::GetType()
{
	return type;
}

glm::vec3 Light::GetVec()
{
	return vec;
}
