#ifndef BARBARIA_INPUTS_GLOBAL_H
#define BARBARIA_INPUTS_GLOBAL_H

#include <glm/glm.hpp>

extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUP;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUP = glm::vec3(0.0f, 1.0f, 0.0f);

#endif //BARBARIA_INPUTS_GLOBAL_H
