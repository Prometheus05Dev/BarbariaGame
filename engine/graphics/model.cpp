#include "model.h"

int Model::modelCounter = 0;
std::vector<float> Model::spawnX = {0};
std::vector<float> Model::spawnY = {0};
std::vector<float> Model::spawnZ = {0};

Model::Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices) {
    spawnX.push_back(x);
    spawnY.push_back(y);
    spawnZ.push_back(z);
    modelCounter = modelCounter + 1;
    myNumber = modelCounter;
}

Model::Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices,
             TextureBuffer *textures, std::string bindOrder) {

    spawnX.push_back(x);
    spawnY.push_back(y);
    spawnZ.push_back(z);
    modelCounter = modelCounter + 1;
    myNumber = modelCounter;
}

void Model::scale(float x, float y, float z) {
    modelMatrix = glm::scale(modelMatrix, glm::vec3(x, y, z));
}

void Model::rotate(float degrees, float x, float y, float z) {
    modelMatrix = glm::rotate(modelMatrix, degrees, glm::vec3(x, y, z));
}

void Model::transform(float x, float y, float z) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
}

Model::~Model() {
    modelCounter = modelCounter - 1;
}