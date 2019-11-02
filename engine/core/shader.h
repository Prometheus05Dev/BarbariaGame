#ifndef BARBARIACLION_SHADER_H
#define BARBARIACLION_SHADER_H

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include <iostream>

class Shader {
public:
    Shader();
    Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
    virtual ~Shader();
    void bind();
    void unbind();
    GLuint getShaderID();
private:
    GLuint compile(std::string shaderSource, GLenum type);
    std::string parse(const char* filename);
    GLuint createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
    GLuint shaderID;
    int uniformLocation;
    static glm::mat4 exampleMatrix;
};

#endif //BARBARIACLION_SHADER_H
