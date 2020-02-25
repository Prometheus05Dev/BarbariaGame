#include "gamewindow.h"

GameWindow::GameWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    this->mainWindow = glfwCreateWindow(400, 200, "Barbaria",NULL, NULL);
    if(this->mainWindow == NULL) {
        std::cout << "Creation of gameWindow failed!" << std::endl;
        glfwTerminate();
    }
    glViewport(0, 0, 400, 200);
    //glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);
    glfwMakeContextCurrent(this->mainWindow);
    //glfwSetInputMode(gameWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //glfwSetCursorPosCallback(gameWindow, mouse_callback);
}

bool GameWindow::shouldClose() {
    if(glfwWindowShouldClose(mainWindow) == true){
        return true;
    }
    if(glfwWindowShouldClose(mainWindow) == false){
        return false;
    }
}

void GameWindow::update() {
    glfwSwapBuffers(mainWindow);
}

void GameWindow::processInput() {
    if(glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(mainWindow, true);
}