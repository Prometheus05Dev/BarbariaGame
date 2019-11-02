#ifndef BARBARIACLION_EXT_DECL_H
#define BARBARIACLION_EXT_DECL_H

#include <glm/glm.hpp>
#include <iostream>
#include <GLFW/glfw3.h>

extern GLFWwindow* mainWindow;
extern glm::mat4 cameraView;
extern bool gameShallClose;
extern int screenWidth;
extern int screenHeight ;

extern void getAttributes();
extern void createWindow();

struct Vertex{
    float x;
    float y;
    float z;
    float textureX;
    float textureY;
};


#endif //BARBARIACLION_EXT_DECL_H
