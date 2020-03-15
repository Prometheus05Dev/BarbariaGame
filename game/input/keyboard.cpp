#include "keyboard.h"

KeyBoard::KeyBoard(){

}

void KeyBoard::processInput() {
    if(glfwGetKey(processWindow, GLFW_KEY_W) == GLFW_PRESS)
        std::cout << "Moving forward" << std::endl;
}
