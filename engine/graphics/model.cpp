#include "model.h"

Model::Model(Vertex *vertexData, int numVertices, GLuint *indices, int numIndices) {
    this->vertexData = vertexData;
    this->numVertices = numVertices;
    this->indices = indices;
    this->numIndices = numIndices;
}

Model::Model(VertexWT *vertexData, int numVertices, GLuint *indices, int numIndices, const char *texturePath) {
    this->vertexTData = vertexData;
    this->numVertices = numVertices;
    this->indices = indices;
    this->numIndices = numIndices;
    this->texturePath = texturePath;
    texture = true;
}

Model::Model(VertexWT *vertexData, int numVertices, GLuint *indices, int numIndices, const char **texturePathes,
             const char *bindOrder) {
    this->vertexTData = vertexData;
    this->numVertices = numVertices;
    this->indices = indices;
    this->numIndices = numIndices;
    this->texturePathes = texturePathes;
    this->bindOrder = bindOrder;
    texture = true;
}