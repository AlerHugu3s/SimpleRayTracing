#include <iostream>
#include"Scene.h"
#include<glm/glm.hpp>

int main()
{
    Scene scene = Scene(500, 500);
    
    UL = glm::vec3(-1, 1, -1);
    UR = glm::vec3(1, 1, -1);
    LR = glm::vec3(1, -1, -1);
    LL = glm::vec3(-1, -1, -1);
    scene.render();

    return 0;
}
