#include <iostream>
#include"Scene.h"
#include<glm/glm.hpp>

int main()
{
    Scene scene = Scene(999, 999);
    
    UL = glm::vec3(-1, 1, -3);
    UR = glm::vec3(1, 1, -3);
    LR = glm::vec3(1, -1, -3);
    LL = glm::vec3(-1, -1, -3);
    scene.render();

    return 0;
}
