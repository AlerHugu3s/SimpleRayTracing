#include "Raytracer.h"

#include <algorithm>

glm::vec3 Raytracer::trace(Ray& ray, int depth, Color* color)
{
    if (depth == 1) color->SetRGBA(0, 0, 0, 0);
    else if (depth > 10) {
        return glm::vec3(0, 0, 0);
    }
    glm::vec3 tempColor[3];
    glm::vec3 tempPoint[3];
    for (int i = 0; i < 3; i++)
    {
        tempColor[i] = glm::vec3(0, 0, 0);
    }
    int index = 0;
    float tempDepth = 9999.0f;
    

    for (int i = 0; i < 3; i++)
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
                glm::vec3 diffuse = (*sphere[i]).diffuse;
                glm::vec3 specular = (*sphere[i]).specular;
                float shininess = (*sphere[i]).shininess;

                if (lights[j]->GetType() == pointLight)
                {
                    lightRay = Ray(result, glm::normalize(lights[j]->GetVec() - result));
                    for (int k = 0; k < 3; k++)
                    {
                        if ((*sphere[k]).intersect(&lightRay, true) == glm::vec3(0, 0, 0))
                        {
                            float dist = glm::distance(lights[j]->GetVec(), result);

                            float lightIntensity = lights[j]->intensity *(1.0f / (1.0f + dist * 0.25 + dist * dist * 0.05));

                            glm::vec3 L = glm::normalize(lights[j]->GetVec() - result);
                            float NdotL = glm::dot(N, L);

                            glm::vec3 H = glm::normalize(L + eyeDir);
                            float NdotH = glm::dot(N, H);

                            glm::vec3 lambert = diffuse * lightIntensity * std::max(NdotL, 0.0f);
                            glm::vec3 phong = specular * lightIntensity * pow(std::max(NdotH, 0.0f), shininess);
                            glm::vec3 lightVal = lambert + phong;

                            tempColor[i] += lightVal;
                            //color->AddRGBA(lightVal.r, lightVal.g, lightVal.b, 0);
                        }
                    }
                }
                else if (lights[j]->GetType() == directionLight)
                {
                    lightRay = Ray(result, lights[j]->GetVec());
                    for (int k = 0; k < 3; k++)
                    {
                        if ((*sphere[k]).intersect(&lightRay, true) == glm::vec3(0, 0, 0))
                        {
                            float lightIntensity = lights[j]->intensity;
                            glm::vec3 L = lights[j]->GetVec();
                            float NdotL = glm::dot(N, L);

                            glm::vec3 H = glm::normalize(L + eyeDir);
                            float NdotH = glm::dot(N, H);

                            glm::vec3 lambert = diffuse * lightIntensity * std::max(NdotL, 0.0f);
                            glm::vec3 phong = specular * lightIntensity * pow(std::max(NdotH, 0.0f), shininess);
                            glm::vec3 lightVal = lambert + phong;

                            tempColor[i] += lightVal;
                            //color->AddRGBA(0.05, 0.05, 0, 0);
                        }
                        else {
                            int b = 0;
                        }
                    }
                }
            }

            continue;
        }
    }

    if (tempDepth == 9999.0f) 
        return glm::vec3(0, 0, 0);

    if (depth ==3 && tempColor[index]!=glm::vec3(0,0,0) && tempColor[index].z!=0)
    {

        int k = 2;
    }
       

    glm::vec3 reflectN = glm::normalize(tempPoint[index] - (*sphere[index]).center);
    glm::vec3 reflectVector = tempPoint[index] - 2 * glm::dot(tempPoint[index], reflectN) * reflectN;
    Ray reflectRay = Ray(tempPoint[index], reflectVector);
    glm::vec3 lightVec = trace(reflectRay, depth + 1, color);

    
    if (depth != 1) {
        lightVec = (lightVec + tempColor[index]) * (1.0f / (1.0f + ray.t * 2 + ray.t * ray.t * 1));
    }
    else
    {
        lightVec = lightVec + tempColor[index];
        color->AddRGBA(lightVec.x, lightVec.y, lightVec.z, 0);
    }

    return lightVec;
}
