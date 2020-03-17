#ifndef BARBARIA_MOUSE_H
#define BARBARIA_MOUSE_H

#include <engine/graphics/camera.h>
#include <GLFW/glfw3.h>

class Mouse {
public:
    Mouse();
    static void mouse_callback_function(GLFWwindow *processWindow, double xpos, double ypos);
    static bool firstMouseMovement;
    static float lastX;
    static float lastY;
    static float xOffSet;
    static float yOffSet;
    static Camera *processCamera;
protected:
private:
};

#endif //BARBARIA_MOUSE_H
