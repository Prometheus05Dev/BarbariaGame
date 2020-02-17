#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "api/loader.h"
#include "engine/graphics/cubeObject.h"
#include "game/camera/framebuffer.h"
#include "game/camera/movement/mouse.h"
#include "game/camera/movement/keyboard.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float currentFrame = glfwGetTime();

glm::mat4 projectionMatrix = glm::mat4(1.0f);
glm::mat4 viewMatrix = glm::mat4(1.0f);
glm::mat4 modelMatrix = glm::mat4(1.0f);

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

    CubeObject testTriangle;

    projectionMatrix = glm::perspective(glm::radians(45.0f), 400.0f / 200.0f, 0.1f, 100.0f);
    glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));

    while(!glfwWindowShouldClose(gameWindow)){
        currentFrame = glfwGetTime();
        returnMainWorld().mainTick.deltaTime = currentFrame - returnMainWorld().mainTick.lastFrame;
        returnMainWorld().mainTick.lastFrame = currentFrame;
        glfwSwapBuffers(gameWindow);
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        returnMainWorld().mainCamera.updateCamera();
        glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("viewMatrix"), 1, GL_FALSE, glm::value_ptr(returnMainWorld().mainCamera.viewMatrix));
        glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
        testTriangle.bind();
        glfwPollEvents();
        processInput(gameWindow);
    }

    return 0;
}
