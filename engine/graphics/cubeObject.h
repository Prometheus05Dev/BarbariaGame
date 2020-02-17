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
    float vertices[108];
};

#endif //BARBARIA_CUBEOBJECT_H
