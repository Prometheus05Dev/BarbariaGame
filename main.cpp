#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <GL/glew.h>
#include "game.h"
#include "engine/graphics/object.h"
#include <GLFW/glfw3.h>
#include <game/windows/gamewindow.h>
#include <api/loader.h>
#include <game/input/keyboard.h>
#include <game/input/mouse.h>
#include <engine/graphics/texture.h>

bool shouldClose = false;

int main() {
    Game game;
    GameWindow gameWindow;
    glEnable(GL_DEPTH_TEST);
    std::cout << "Hello, World!" << std::endl;
    glewExperimental = GL_TRUE;
    glewInit();
    Loader gameLoader;
    Shader gameShader = gameLoader.loadShader();
    gameShader.bind();
    Camera gameCamera(gameShader);
    KeyBoard gameKeyboard;
    gameKeyboard.processWindow = gameWindow.mainWindow;
    Mouse gameMouse;
    Mouse::processCamera = &gameCamera;
    glfwSetCursorPosCallback(gameWindow.mainWindow, &gameMouse.mouse_callback_function);

    Object testObject("stall.obj");
    Texture testTexture("stall.png");

    while(!shouldClose){
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gameShader.bind();
        testTexture.bind();
        testObject.bind();
        gameWindow.update();
        glfwPollEvents();
        gameWindow.processInput();
        gameKeyboard.processInput(gameCamera);
        gameCamera.update();
        if(gameWindow.shouldClose() == true){
            glfwTerminate();
            shouldClose = true;
        }
        game.update(glfwGetTime());
    }

    return 0;
}
