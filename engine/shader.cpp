#include "shader.h"
using namespace std;
Shader::Shader(const char* vertexShaderFilename,const char* fragmentShaderFilename){
    shaderID = createShader(vertexShaderFilename, fragmentShaderFilename);
}
Shader::~Shader(){
    glDeleteProgram(shaderID);
}
void Shader::bind(){
    glUseProgram(shaderID);
}
void Shader::unbind(){
    glUseProgram(0);
}
GLuint Shader::getShaderID(){
    return shaderID;
}
GLuint Shader::compile(string shaderSource, GLenum type){
    GLuint ID = glCreateShader(type);
    const char* sourceShader = shaderSource.c_str();
    glShaderSource(ID, 1, &sourceShader, 0);
    glCompileShader(ID);
    int result;
    glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
    if(result != GL_TRUE){
        int length = 0;
        glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        glGetShaderInfoLog(ID, length, &length, message);
        cout << "Shader compile error: " << message << endl;
        delete[] message;
        return 0;
    }
    return ID;
}
string Shader::parse(const char* filename){
    FILE* shaderFile;
    shaderFile = fopen(filename, "rb");
    if(shaderFile == nullptr){
        cout << "File " << filename << " not found." << endl;
        return 0;
    }
    string contents;
    fseek(shaderFile, 0, SEEK_END);
    size_t filesize = ftell(shaderFile);
    rewind(shaderFile);
    contents.resize(filesize);
    fread(&contents[0], 1, filesize, shaderFile);
    fclose(shaderFile);
    return contents;
}
GLuint Shader::createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename){
    string vertexShaderSource = parse(vertexShaderFilename);
    string fragmentShaderSource = parse(fragmentShaderFilename);
    GLuint shaderProgram = glCreateProgram();
    GLuint vertexShader = compile(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    return shaderProgram;
}
