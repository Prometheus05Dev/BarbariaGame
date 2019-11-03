#ifndef BARBARIACLION_EXT_DECL_H
#define BARBARIACLION_EXT_DECL_H

#include <core/shader.h>
#include <glm/glm.hpp>
#include <iostream>
#include <GLFW/glfw3.h>
#include <filesystem>

extern glm::vec3 cameraPosition;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;

extern float deltaTime;
extern float lastTick;
extern float cameraSpeed;

extern GLFWwindow* mainWindow;

extern glm::mat4 cameraView;

extern bool gameShallClose;

extern int screenWidth;
extern int screenHeight;

extern Shader barbariaObjectShader;


extern void getAttributes();
extern void createWindow();
extern void createShader(Shader *shader);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void calculateTickDuration();


struct Vertex{
    float x;
    float y;
    float z;
    float textureX;
    float textureY;
};


#endif //BARBARIACLION_EXT_DECL_H
