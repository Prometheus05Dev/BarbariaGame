#include "mouse.h"

Camera *Mouse::processCamera = nullptr;

bool Mouse::firstMouseMovement = true;

float Mouse::lastX = 0.0f;
float Mouse::lastY = 0.0f;
float Mouse::xOffSet = 0.0f;
float Mouse::yOffSet = 0.0f;

Mouse::Mouse() {

}

void Mouse::mouse_callback_function(GLFWwindow *processWindow, double xpos, double ypos) {
    if(firstMouseMovement){
        lastX = xpos;
        lastY = ypos;
        firstMouseMovement = false;
    }
    xOffSet = xpos - lastX;
    yOffSet = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    processCamera->processMouseMovement(xOffSet, yOffSet);
}
