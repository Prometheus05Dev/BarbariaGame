#ifndef BARBARIA_KEYBOARD_H
#define BARBARIA_KEYBOARD_H

#include "../../../extern_world.h"
#include <GLFW/glfw3.h>
#include "../inputs_global.h"

extern float cameraSpeed;
float cameraSpeed = 0.0f;

void processInput(GLFWwindow *window);

#endif //BARBARIA_KEYBOARD_H
