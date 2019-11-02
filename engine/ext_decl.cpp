#include "ext_decl.h"

bool gameShallClose = false;

int screenWidth = 0;
int screenHeight = 0;
GLFWwindow* mainWindow = 0;
glm::mat4 cameraView = glm::mat4(1.0f);
Shader barbariaObjectShader = Shader();

void createWindow(){
    mainWindow= glfwCreateWindow(1920, 1080, "Barbaria", NULL, NULL);
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