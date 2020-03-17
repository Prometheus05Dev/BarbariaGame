#include "gamewindow.h"

GameWindow::GameWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    this->mainWindow = glfwCreateWindow(1920, 1080, "Barbaria",glfwGetPrimaryMonitor(), NULL);
    if(this->mainWindow == NULL) {
        std::cout << "Creation of gameWindow failed!" << std::endl;
        glfwTerminate();
    }
    glViewport(0, 0, 1920, 1080);
    //glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);
    glfwMakeContextCurrent(this->mainWindow);
    glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
