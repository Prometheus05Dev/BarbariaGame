#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "engine/shader.h"
#include "engine/buffers.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int main(){
    glEnable(GL_DEPTH_TEST);
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Barbaria", glfwGetPrimaryMonitor(), NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glewExperimental = true;
    glewInit();
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.0f, 100.0f);

    Shader mainShader("/home/janek/CLionProjects/Barbaria/shaders/VertexShader.glsl", "/home/janek/CLionProjects/Barbaria/shaders/FragmentShader.glsl");
    mainShader.bind();

    Vertex triangle[] = {
            Vertex{-0.5f, -0.5f, 0.0f},
            Vertex{0.5f, -0.5f, 0.0f},
            Vertex{0.0f, 0.5f, 0.0f}
    };

    GLuint indices[] = {
            0, 1, 2
    };
    IndexBuffer mainIndex(indices, 3);

    VertexBuffer mainBuffer(triangle, 9);
    trans = glm::rotate(trans, glm::radians(-55.0f), glm::vec3(1.0, 0.1, 0.5));

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        unsigned int transformLoc = glGetUniformLocation(mainShader.shaderID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        unsigned int viewLoc = glGetUniformLocation(mainShader.shaderID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        unsigned int projectionLoc = glGetUniformLocation(mainShader.shaderID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
        processInput(window);
        mainBuffer.vBind();
        mainIndex.iBind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}