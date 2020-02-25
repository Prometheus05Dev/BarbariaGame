#ifndef BARBARIA_CUBEOBJECT_H
#define BARBARIA_CUBEOBJECT_H

#include <GL/glew.h>

class CubeObject {
public:
    CubeObject();
    void bind();
protected:
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    float vertices[24];
    unsigned int indices[36];
};


#endif //BARBARIA_CUBEOBJECT_H
