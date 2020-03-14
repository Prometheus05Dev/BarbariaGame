#include "game.h"

Game::Game() {
    this->gameWindow = new GameWindow();
    shouldClose = false;
}

void Game::postInit() {
    this->gameLoader = new Loader();
    gameShader = this->gameLoader->loadShader();
    this->gameShader->bind();
    gameCamera = new Camera(*this->gameShader);
}

void Game::update() {
    this->gameWindow->update();
    glfwPollEvents();
    this->gameWindow->processInput();
    if(this->gameWindow->shouldClose() == true){
        shouldClose == true;
        glfwTerminate();
    }
}