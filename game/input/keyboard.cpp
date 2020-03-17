#include "keyboard.h"

KeyBoard::KeyBoard(){

}

void KeyBoard::processInput(Camera &camera) {
    if(glfwGetKey(processWindow, GLFW_KEY_W) == GLFW_PRESS)
        camera.moveForward();
    if(glfwGetKey(processWindow, GLFW_KEY_S) == GLFW_PRESS)
        camera.moveBackward();
    if(glfwGetKey(processWindow, GLFW_KEY_D) == GLFW_PRESS)
        camera.moveRight();
    if(glfwGetKey(processWindow, GLFW_KEY_A) == GLFW_PRESS)
        camera.moveLeft();
}
