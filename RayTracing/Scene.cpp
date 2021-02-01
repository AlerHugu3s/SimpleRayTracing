#include "Scene.h"
#include<iostream>

int screenWitdh, screenHeight;
glm::vec3 interval_X, interval_Y;
glm::vec3 UL, UR, LR, LL;
Light* lights[2];
Sphere* sphere[5];
Scene::Scene(int x, int y)
{
    screenWitdh = x;
    screenHeight = y;
}
// This is the main rendering loop
void Scene::render()
{
    Sampler sampler;
    Sample sample = Sample(0, 0);
    Film film;
    Camera camera = Camera(glm::vec3(0,0,0));
    sphere[0] = new Sphere(2, glm::vec3(0, 0, -17), glm::vec3(1,0,0), glm::vec3(1,1,1),50.0f);
    sphere[1] = new Sphere(1.5f, glm::vec3(0, 4, -17), glm::vec3(0, 1, 0), glm::vec3(1, 1, 1), 50.0f);
    sphere[2] = new Sphere(1.5f, glm::vec3(0, -4, -17), glm::vec3(0, 0, 1), glm::vec3(1, 1, 1), 50.0f);
    sphere[3] = new Sphere(1.5f, glm::vec3(4, 0, -17), glm::vec3(1, 0, 1), glm::vec3(1, 1, 1), 50.0f);
    sphere[4] = new Sphere(1.5f, glm::vec3(-4, 0, -17), glm::vec3(0, 1, 1), glm::vec3(1, 1, 1), 50.0f);
    Raytracer raytracer = Raytracer();
    Color color = Color(0, 0, 0, 0);
    Ray ray = Ray();
    lights[0] = new DirectionalLight(1, glm::vec3(-0.57735027f,0.57735027f,0.57735027f));
    lights[1] = new DirectionalLight(1,glm::vec3(0.57735027f, -0.57735027f, -0.57735027f));
    while (sampler.getSample(&sample)) {
        camera.GenerateRay(sample, &ray);
        //std::cout << "StartTracing:  " << sample.x << "  " << sample.y << "\n";
        if (sample.x == 718 && sample.y == 508)
        {
            int f = 0;
        }

        raytracer.trace(ray, 1,&color);
        film.commit(sample, color);
    }

    film.writeImage();
}

