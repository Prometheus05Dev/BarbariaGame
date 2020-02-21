#include "game.h"

Game::Game() {
    this->gameWindow = new GameWindow();
    shouldClose = false;
}

void Game::postInit() {
    this->gameLoader = new Loader();
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