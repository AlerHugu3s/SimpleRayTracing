#include "Camera.h"
#include"Scene.h"

glm::vec3 eyePos;
Camera::Camera(glm::vec3 eyePos)
{
	eyePos = eyePos;
	xVec = UR - UL;
	yVec = LR - UR;
	interval_X = xVec/(float)screenWitdh;
	interval_Y = yVec/(float)screenHeight;
}

void Camera::GenerateRay(Sample& sample, Ray* ray)
{
	if (sample.x == 250)
	{
		if (sample.y == 250)
		{
			int i = 1;
		}
	}
	Ray temp = Ray(eyePos, UL + interval_X*(float)sample.x + interval_Y*(float)sample.y);
	*ray = temp;
}
