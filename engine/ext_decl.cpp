#include "ext_decl.h"

float deltaTime = 0.0f;
float cameraSpeed = 0.0f;
float lastTick = 0.0f;
float previousFPS = 0.0f;

bool gameShallClose = false;

World enteredWorld = World();

int screenWidth = 0;
int screenHeight = 0;
int FPS = 0;

GLFWwindow* mainWindow = 0;

glm::mat4 cameraView = glm::mat4(1.0f);

Shader barbariaObjectShader = Shader();

glm::vec3 cameraFront(0.0f, 0.0f, 0.0f);
glm::vec3 cameraPosition(0.0f, 0.0f, 0.0f);
glm::vec3 cameraUp(0.0f, 0.0f, 0.0f);

void createWindow(){
    const GLFWvidmode *monitorSize = glfwGetVideoMode(glfwGetPrimaryMonitor());
    mainWindow= glfwCreateWindow(monitorSize->width, monitorSize->height, "Barbaria", NULL, NULL);
    glfwMakeContextCurrent(mainWindow);
    std::cout << "[INFO] You are a wizard, Harry!" << std::endl;
}

void getAttributes(){
   glfwGetWindowSize(mainWindow, &screenWidth, &screenHeight);
}

void createBarbariaObjectShader(){
    namespace fileSystem = std::filesystem;
    fileSystem::path relativeVertexShaderPath = "../resources/shaders/objects_default/VertexShader.glsl";
    fileSystem::path relativeFragmentShaderPath = "../resources/shaders/objects_default/FragmentShader.glsl";
    fileSystem::path absoluteVertexShaderPath = fileSystem::absolute(relativeVertexShaderPath);
    fileSystem::path absoluteFragmentShaderPath = fileSystem::absolute(relativeFragmentShaderPath);
    std::string vertexShaderPathString = absoluteVertexShaderPath.u8string();
    std::string fragmentShaderPathString = absoluteFragmentShaderPath.u8string();
    const char* vertexShaderPath = vertexShaderPathString.c_str();
    const char* fragmentShaderPath = fragmentShaderPathString.c_str();
    barbariaObjectShader = Shader(vertexShaderPath, fragmentShaderPath);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void calculateTickDuration(){
    float currentTick = glfwGetTime();
    deltaTime = currentTick - lastTick;
    lastTick = currentTick;
}

void FPSUpdate(){
   float currentTime = glfwGetTime();
   FPS = FPS + 1;
   if(currentTime - previousFPS >= 1.0){
       std::cout << "FPS: " << FPS << std::endl;
       previousFPS = currentTime;
       //First check if world is entered
       gameLoop();
       FPS = 0;
   }
}