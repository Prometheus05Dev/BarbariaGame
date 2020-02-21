#ifndef BARBARIA_GAMEWINDOW_H
#define BARBARIA_GAMEWINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow {
public:
    GameWindow();
    bool shouldClose();
    GLFWwindow *mainWindow;
    void update();
    void processInput();
protected:
private:
};

#endif //BARBARIA_GAMEWINDOW_H
