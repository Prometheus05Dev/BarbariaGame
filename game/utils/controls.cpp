#include "controls.h"

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        std::cout << "Seems like everything worked correctly and the program has been shut down by user. Good bye! Greetings ~Prometheus05" << std::endl;
        gameShallClose = true;
    }
    cameraSpeed = 2.5f * deltaTime;
    //Move Forward
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPosition += cameraSpeed * cameraFront;
    //Move Backwards
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPosition -= cameraSpeed * cameraFront;
    //Move to the right
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    //Move to the left
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
}