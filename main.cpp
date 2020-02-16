#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game/world/world.h"
#include "api/loader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* gameWindow = glfwCreateWindow(400, 200, "Barbaria",NULL, NULL);
    if(gameWindow == NULL) {
        std::cout << "Creation of gameWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glViewport(0, 0, 1920, 1080);
    glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);
    glfwMakeContextCurrent(gameWindow);
    //glfwSetInputMode(gameWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(gameWindow, mouse_callback);
    glEnable(GL_DEPTH_TEST);
    std::cout << "Hello, World!" << std::endl;
    glewExperimental = GL_TRUE;
    glewInit();
    World mainWorld;
    while(!glfwWindowShouldClose(gameWindow)){
        processInput(gameWindow);
    }
    return 0;
}
