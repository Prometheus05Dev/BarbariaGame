#include "game.h"

float Game::deltaTime = 0.0f;

Game::Game() {
    currentFrame = 0.0f;
    lastFrame = 0.0f;
}

void Game::update(float currentTime) {
    currentFrame = currentTime;
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}