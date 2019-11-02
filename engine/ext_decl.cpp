#include "ext_decl.h"

bool gameShallClose = false;

int screenWidth = 0;
int screenHeight = 0;
GLFWwindow* mainWindow = 0;

void createWindow(){
    mainWindow= glfwCreateWindow(1920, 1080, "Barbaria", NULL, NULL);
    glfwMakeContextCurrent(mainWindow);
    std::cout << "[INFO] You are a wizard, Harry!" << std::endl;
}

void getAttributes(){
   glfwGetWindowSize(mainWindow, &screenWidth, &screenHeight);
}