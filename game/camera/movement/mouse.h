#ifndef BARBARIA_MOUSE_H
#define BARBARIA_MOUSE_H

#include <GLFW/glfw3.h>

extern bool firstMouse;
extern float lastX;
extern float lastY;
extern float yaw;
extern float pitch;

bool firstMouse = true;
float lastX = 800.0f / 2.0f;
float lastY = 600.0f / 2.0f;
float yaw = -90.0f;
float pitch = 0.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

#endif //BARBARIA_MOUSE_H
