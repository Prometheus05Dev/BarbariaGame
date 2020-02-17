#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game/world/world.h"
#include "api/loader.h"
#include "game/input/framebuffer.h"
#include "game/input/mouse.h"
#include "game/input/keyboard.h"

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
    glViewport(0, 0, 400, 200);
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
        glfwSwapBuffers(gameWindow);
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        processInput(gameWindow);
    }

    return 0;
}
