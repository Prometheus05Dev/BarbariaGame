#include <iostream>
#include <GL/glew.h>
#include "game.h"
#include "engine/graphics/object.h"
#include <glm/glm.hpp>
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>

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

    Object testObject("hi.obj");


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
