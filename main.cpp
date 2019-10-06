#include "engine/buffers.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "engine/declarations.h"
#include "engine/shader.h"
#include "engine/model.h"
#include "engine/camera.h"
#include "game/block.h"
#include "game/chunk.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float currentFrame = 0.0f;
glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float lastX = 960.0f;
float lastY = 540.0f;
float offsetX = 0.0f;
float offsetY = 0.0f;
float sensitivity = 0.005f;
float yaw = 0.0f;
float pitch = 0.0f;
bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    offsetX = xpos - lastX;
    offsetY = lastY - ypos;
    offsetX *= sensitivity;
    offsetY *= sensitivity;
    yaw = glm::mod(yaw + offsetX, 360.0f);
    yaw += offsetX; //offsetX
    pitch += offsetY; //offsetY
    if(pitch >= 89.0f) pitch = 88.0f;
    if(pitch <= -89.0f) pitch = -88.0f;
    cameraFront.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    cameraFront.y = sin(glm::radians(pitch));
    cameraFront.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    cameraFront = glm::normalize(cameraFront);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    float cameraSpeed = 2.5f * deltaTime;
    //std::cout << cameraSpeed;
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPosition += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPosition -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        
}
int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    GLFWwindow* mainWindow = glfwCreateWindow(1920, 1080, "Barbaria", NULL, NULL);
    //glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(mainWindow);
    GLenum err;
    glewExperimental = true;
    if ((err = glewInit()) != GLEW_OK)
        std::cout << glewGetErrorString(err) << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << "End" << std::endl;

    bool open = true;
    //GrassBlock exampleGrassBlock = GrassBlock();
    //GrassBlock exampleGrassBlock2 = GrassBlock();
    glViewport(0, 0, 1900, 1800);
    glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);
    glfwSetCursorPosCallback(mainWindow, mouse_callback);
    Camera fpsCamera;
    Shader defaultShader;
    defaultShader.bind();
    int shaderUniformLocation = defaultShader.getShaderID();
    int shaderUniformLocationi = glGetUniformLocation(shaderUniformLocation, "u_texture");
    glUniform1i(shaderUniformLocationi, 0);
    //glm::vec3 rotationExample = glm::vec3(1.0f, 0.0f, 0.0f);
    //glm::vec3 transformExample = glm::vec3(1.0f, 0.0f, 0.0f);
    float radius = 10.0f;
    glEnable(GL_DEPTH_TEST);
    //exampleGrassBlock.transform(transformExample);
    //GameLoop
    Chunk myChunk = Chunk();
    myChunk.create();
    while(!glfwWindowShouldClose(mainWindow)){
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(mainWindow);
        glm::mat4 cameraView = fpsCamera.updateCam(cameraPosition, cameraFront, cameraUp);
        //exampleGrassBlock.rotate(1, rotationExample);
        //exampleGrassBlock2.rotate(1, rotationExample);
        //exampleGrassBlock.update(cameraView);
        //exampleGrassBlock2.update(cameraView);
        myChunk.update(cameraView);
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }
    defaultShader.unbind();
    glfwTerminate();
    return 255;
}
