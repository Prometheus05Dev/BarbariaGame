#ifndef BARBARIACLION_MODEL_H
#define BARBARIACLION_MODEL_H

#include "buffers.h"

class Model{
public:
    Model(Vertex *vertexData, int numVertices, GLuint *indices, int numIndices); //Constructor for models WITHOUT texture
    Model(VertexWT *vertexData, int numVertices, GLuint* indices, int numIndices, const char* texturePath); //Constructor for models WITH  ONE texture
    Model(VertexWT *vertexData, int numVertices, GLuint* indices, int numIndices, const char* *texturePathes, const char* bindOrder); //Constructor for models WITH texture
protected:
    bool texture = false;
    Vertex *vertexData;
    VertexWT *vertexTData;
    int numVertices;
    GLuint* indices;
    int numIndices;
    const char* texturePath;
    const char* *texturePathes;
    const char* bindOrder;
};

#endif //BARBARIACLION_MODEL_H
