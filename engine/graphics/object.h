#ifndef BARBARIA_OBJECT_H
#define BARBARIA_OBJECT_H

#include <GL/glew.h>

class Object {
public:
    Object();
    void bind();
protected:
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    float vertices[64];
    unsigned int indices[36];
};


#endif //BARBARIA_OBJECT_H
