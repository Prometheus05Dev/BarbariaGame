// INCLUDES
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game/utils/controls.h"
#include "game/utils/declarations.h"

// VARIABLES + FUNCTIONS


int main(){
    // INITIALIZE GAME

    std::cout << "Hello World!" << std::endl;
    std::cout << "Trying my best to load the game... 50:50 chance!" << std::endl;

    glewExperimental = true;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    std::cout << "All the window hints and contexts configured, now make ready for the magic moment of the (hopefully) appearing window!" << std::endl;

    GLFWwindow* mainWindow = glfwCreateWindow(1920, 1080, "Barbaria", NULL, NULL);
    glfwMakeContextCurrent(mainWindow);
    std::cout << "You are a wizard, Harry!" << std::endl;

    std::cout << "This are you're hardware and driver information, which are relevant to OpenGl:" << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    GLenum initError;
    if((initError = glewInit()) != GLEW_OK){
        std::cout << "A fatal occured while initializing OpenGL(GLEW). Please report this crash-report to Prometheus05!" << std::endl;
        std::cout << glewGetErrorString(initError) << std::endl;
        std::cout << "This wasn't supposed to happen!" << std::endl;
    }

    glViewport(0, 0, 1920, 1080);
    glEnable(GL_DEPTH_TEST);


    // GAME MAIN LOOP
    while(!gameShallClose){

        // Clear screen -> background e.g.: sky
        glClearColor(0.0f, 153.0f, 153.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Process Inputs and signals and every thing what has to be processed
        processInput(mainWindow);

        // Gather everything to draw
        // Bind, Unbind, Draw!

        //Swap Buffers -> less flickering! And collect events
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }

    // END
    // Run post scripts, final log and kill window
    std::cout << "Seems like everything worked correctly and the program has been shut down by user. Good bye! Greetings ~Prometheus05" << std::endl;
    glfwTerminate();
}