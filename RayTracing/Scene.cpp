#include "Scene.h"
#include<iostream>

int screenWitdh, screenHeight;
glm::vec3 interval_X, interval_Y;
glm::vec3 UL, UR, LR, LL;
Light* lights[2];
Sphere* sphere[3];
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
    sphere[0] = new Sphere(0.5f, glm::vec3(0.7f, 0.7f, -2), glm::vec3(1,0,1), glm::vec3(1,1,1),100.0f);
    sphere[1] = new Sphere(0.5f, glm::vec3(-1, -1, -3), glm::vec3(1, 1, 0), glm::vec3(1, 1, 1), 100.0f);
    sphere[2] = new Sphere(3, glm::vec3(0, 0, -8), glm::vec3(0.5, 0.5, 0.5), glm::vec3(1, 1, 1), 100.0f);
    Raytracer raytracer = Raytracer();
    Color color = Color(0, 0, 0, 0);
    Ray ray = Ray();
    lights[0] = new DirectionalLight(0.3, glm::vec3(0.5f, 0.5f, 1));
    lights[1] = new PointLight(0.5, glm::vec3(1, -2, -4));
    while (sampler.getSample(&sample)) {
        camera.GenerateRay(sample, &ray);
        //std::cout << "StartTracing:  " << sample.x << "  " << sample.y << "\n";
        raytracer.trace(ray, 1,&color);
        film.commit(sample, color);
    }

    film.writeImage();
}

