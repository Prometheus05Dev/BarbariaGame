#include "controls.h"

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        std::cout << "Seems like everything worked correctly and the program has been shut down by user. Good bye! Greetings ~Prometheus05" << std::endl;
        gameShallClose = true;
    }
}