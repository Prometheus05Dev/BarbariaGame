#include <iostream>
#include <GL/glew.h>
#include "engine/graphics/object.h"
#include "game.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <zconf.h>

float currentFrame = glfwGetTime();

glm::mat4 projectionMatrix = glm::mat4(1.0f);
glm::mat4 viewMatrix = glm::mat4(1.0f);
glm::mat4 modelMatrix = glm::mat4(1.0f);

int main() {
    Game game;
    glEnable(GL_DEPTH_TEST);
    std::cout << "Hello, World!" << std::endl;
    glewExperimental = GL_TRUE;
    glewInit();
    game.postInit();

    CubeObject testObject;

    /*projectionMatrix = glm::perspective(glm::radians(45.0f), 400.0f / 200.0f, 0.1f, 100.0f);
    //glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f)); */

    while(!game.shouldClose){
        //currentFrame = glfwGetTime();
        //returnMainWorld().mainTick.deltaTime = currentFrame - returnMainWorld().mainTick.lastFrame;
        //returnMainWorld().mainTick.lastFrame = currentFrame;
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        testObject.bind();
        game.update();
        //testTriangle.bind();
        //returnMainWorld().mainCamera.updateCamera();
        //glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("viewMatrix"), 1, GL_FALSE, glm::value_ptr(returnMainWorld().mainCamera.viewMatrix));
        //glUniformMatrix4fv(returnMainWorld().mainLoader.mainShader->getShaderLocation("modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    }

    return 0;
}
