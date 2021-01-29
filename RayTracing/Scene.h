#pragma once

#include<glm/glm.hpp>
#include"Film.h"
#include"Raytracer.h"
#include"Camera.h"
#include"DirectionalLight.h"
#include"PointLight.h"

extern int screenWitdh, screenHeight;
extern glm::vec3 interval_X, interval_Y;
extern glm::vec3 UL, UR, LR, LL;
extern Light* lights[2];
extern Sphere* sphere[5];
class Scene
{
public:

	
	Scene(int x, int y);
	void render();

};

