#ifndef BARBARIA_OBJECT_H
#define BARBARIA_OBJECT_H

#include <GL/glew.h>
#include <vector>

struct Vertex {
    float x, y, z;
    float normalX, normalY, normalZ;
    float textureX, textureY;
};

class Object {
public:
    Object();
    void bind();
protected:
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int numIndices = 0;
};


#endif //BARBARIA_OBJECT_H
