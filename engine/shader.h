#pragma once
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <iostream>
using namespace std;
struct Shader {
    Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
    virtual ~Shader();
    void bind();
    void unbind();
    GLuint getShaderID();
    GLuint shaderID;
private:
    GLuint compile(string shaderSource, GLenum type);
    string parse(const char* filename);
    GLuint createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
    int uniformLocation;
    static glm::mat4 exampleMatrix;
};