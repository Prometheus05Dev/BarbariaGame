#include "controls.h"
#include "declarations.h"

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        gameShallClose = true;
    }
}