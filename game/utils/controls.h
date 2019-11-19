#ifndef BARBARIACLION_CONTROLS_H
#define BARBARIACLION_CONTROLS_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "time.h"

extern glm::vec3 cameraPos;
extern glm::vec3 cameraUP;
extern glm::vec3 cameraFront;

extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void processInput(GLFWwindow *window);
extern void mouse_callback(GLFWwindow* window, double xpos, double ypos);

#endif //BARBARIACLION_CONTROLS_H
