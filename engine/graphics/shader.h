#ifndef BARBARIA_SHADER_H
#define BARBARIA_SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void bind();
    std::string readShaderFile(const char *filePath);
    int getShaderLocation(const GLchar* variableName);
    int pushMatrix4f(glm::mat4 matrix, const GLchar* name);
protected:
private:
    const char *vertexShaderSource;
    const char *fragmentShaderSource;
    int shaderProgram = 0;
};

#endif //BARBARIA_SHADER_H
