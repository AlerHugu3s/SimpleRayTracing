#include "Raytracer.h"

#include <algorithm>

glm::vec3 Raytracer::trace(Ray& ray, int depth, Color* color)
{
    if (depth > 5) {
        return glm::vec3(0, 0, 0);
    }

    /*temp values*/
    glm::vec3 tempColor[5];
    glm::vec3 tempPoint[5];
    for (int i = 0; i < 5; i++)
    {
        tempColor[i] = glm::vec3(0, 0, 0);
    }
    int index = 0;
    float tempDepth = 9999.0f;
    

    for (int i = 0; i < 5; i++)
    {
        glm::vec3 result = (*sphere[i]).intersect(&ray, false);

        tempPoint[i] = result;

        if (result == glm::vec3(0, 0, 0))
        {
            continue;
        }
        else {
            //color->AddRGBA(0.1f, 0, 0, 0);
            Ray lightRay;

            if (tempDepth > ray.t) {
                tempDepth = ray.t;
                index = i;
            }

            glm::vec3 N = glm::normalize(result - (*sphere[i]).center);
            glm::vec3 eyeDir = glm::normalize(eyePos - result);

            glm::vec3 R = result - 2*glm::dot(result,N)*N;

            Ray reflectRay = Ray(result, R);

            result += N * 0.01f;
            tempPoint[i] = result;

            for (int j = 0; j < 2; j++)
            {
                float lightIntensity = 0;
                glm::vec3 L;
                if (lights[j]->GetType() == pointLight)
                {
                    lightRay = Ray(result, glm::normalize(lights[j]->GetVec() - result));
                    float dist = glm::distance(lights[j]->GetVec(), result);
                    for (int k = 0; k < 5; k++)
                    {
                        if ((*sphere[k]).intersect(&lightRay, true) != glm::vec3(0, 0, 0))
                        {
                            break;
                        }
                        else if ((*sphere[k]).intersect(&lightRay, true) == glm::vec3(0, 0, 0) && k == 4)
                        {
                            lightIntensity = lights[j]->intensity * (1.0f / (1.0f + dist * 0.25f + dist * dist * 0.05f));
                        }
                    }
                    L = glm::normalize(lights[j]->GetVec() - result);
                }
                else if (lights[j]->GetType() == directionLight)
                {
                    lightRay = Ray(result, lights[j]->GetVec());
                    for (int k = 0; k < 5; k++)
                    {
                        if ((*sphere[k]).intersect(&lightRay, true) != glm::vec3(0, 0, 0))
                        {
                            break;
                        }
                        else if((*sphere[k]).intersect(&lightRay, true) == glm::vec3(0, 0, 0) && k ==4 ){
                            lightIntensity = lights[j]->intensity;
                        }
                    }
                    L = lights[j]->GetVec();
                }
                glm::vec3 H = glm::normalize(L + eyeDir);
                tempColor[i] += LightCompute(N,L,H, (*sphere[i]).diffuse, (*sphere[i]).specular, (*sphere[i]).shininess,lightIntensity);
            }
            continue;
        }
    }

    if (tempDepth == 9999.0f) 
        return glm::vec3(0, 0, 0);
       
    glm::vec3 reflectN = glm::normalize(tempPoint[index] - (*sphere[index]).center);
    glm::vec3 reflectVector = tempPoint[index] - 2 * glm::dot(tempPoint[index], reflectN) * reflectN;
    Ray reflectRay = Ray(tempPoint[index], reflectVector);
    glm::vec3 lightVec = trace(reflectRay, depth + 1, color);

    if (depth != 1) {
        lightVec = (lightVec + tempColor[index]) * (1.0f / (1.0f + ray.t * 0 + ray.t * ray.t * 0));
    }
    else
    {
        lightVec = lightVec + tempColor[index];
        color->SetRGBA(lightVec.x, lightVec.y, lightVec.z, 0);
    }

    return lightVec;
}

glm::vec3 Raytracer::LightCompute(glm::vec3 normalVec, glm::vec3 directionVec, glm::vec3 halfVec, glm::vec3 diffuse, glm::vec3 specular, float shininess,float intensity)
{
    float NdotL = glm::dot(normalVec, directionVec);
    float NdotH = glm::dot(normalVec,halfVec);

    glm::vec3 lambert = diffuse * intensity * std::max(NdotL, 0.0f);
    glm::vec3 phong = specular * intensity * pow(std::max(NdotH, 0.0f), shininess);
    return lambert + phong;
}


