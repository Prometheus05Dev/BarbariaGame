#ifndef BARBARIA_SHADER_H
#define BARBARIA_SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void bind();
    std::string readShaderFile(const char *filePath);
    int getShaderLocation(const GLchar* variableName);
protected:
private:
    const char *vertexShaderSource;
    const char *fragmentShaderSource;
    int shaderProgram = 0;
};

#endif //BARBARIA_SHADER_H
