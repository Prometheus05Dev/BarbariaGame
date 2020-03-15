#ifndef BARBARIA_KEYBOARD_H
#define BARBARIA_KEYBOARD_H

#include <GLFW/glfw3.h>
#include <iostream>

class KeyBoard {
public:
    KeyBoard();
    void processInput();
    GLFWwindow *processWindow;
protected:
private:
};

#endif //BARBARIA_KEYBOARD_H
