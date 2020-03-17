#ifndef BARBARIA_KEYBOARD_H
#define BARBARIA_KEYBOARD_H

#include <engine/graphics/camera.h>
#include <GLFW/glfw3.h>
#include <iostream>

class KeyBoard {
public:
    KeyBoard();
    void processInput(Camera &camera);
    GLFWwindow *processWindow;
protected:
private:
};

#endif //BARBARIA_KEYBOARD_H
