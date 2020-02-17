#include "mouse.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if(firstMouse == true){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

}
