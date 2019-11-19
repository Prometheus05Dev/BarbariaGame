#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "engine/shader.h"
#include "engine/buffers.h"
#include "ext_decl.h"
#include "game/utils/controls.h"
#include "game/utils/time.h"
#include "engine/camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>
//new

Vertex firstTriangle[] = {
        Vertex{0.0f, 0.0f, 0.0f},
        Vertex{1.0f, 0.0f, 0.0f},
        Vertex{1.0f, 0.0f, 1.0f},
        Vertex{0.0f, 0.0f, 1.0f}
};

GLuint firstTriangleIndices[] = {
        0, 1, 2,
        0, 3, 2
};

int main(){
    glDisable(GL_DEPTH_TEST);
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

    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.0f, 100.0f);

    std::filesystem::path currentWorkingDirectory = std::filesystem::current_path();
    std::filesystem::path vertexShaderFS = currentWorkingDirectory / "VertexShader.glsl";
    std::string vertexShaderSTR = vertexShaderFS.u8string();
    const char* vertexShaderPath = vertexShaderSTR.c_str();
    std::filesystem::path fragmentShaderFS = currentWorkingDirectory / "FragmentShader.glsl";
    std::string fragmentShaderSTR = fragmentShaderFS.u8string();
    const char* fragmentShaderPath = fragmentShaderSTR.c_str();

    Shader mainShader(vertexShaderPath, fragmentShaderPath);
    mainShader.bind();

    //trans = glm::rotate(trans, glm::radians(-55.0f), glm::vec3(1.0, 0.0, 0.0));
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 1.0f));

    VertexBuffer mainVertex(firstTriangle, 4);
    IndexBuffer mainIndex(firstTriangleIndices, 6);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);

    cameraView = glm::translate(cameraView, glm::vec3(0.0f, 0.0f, -3.0f));

    while(!glfwWindowShouldClose(window)){
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        unsigned int transformLoc = glGetUniformLocation(mainShader.shaderID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        unsigned int viewLoc = glGetUniformLocation(mainShader.shaderID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cameraView));
        unsigned int projectionLoc = glGetUniformLocation(mainShader.shaderID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
        mainVertex.vBind();
        mainIndex.iBind();
        processInput(window);
        cameraView = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUP);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}