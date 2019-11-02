#include "model.h"

int Model::modelCounter = 0;
std::vector<float> Model::spawnX = {0};
std::vector<float> Model::spawnY = {0};
std::vector<float> Model::spawnZ = {0};

Model::Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices) : IndexBuffer(indexData, numIndices), VertexBuffer(vertexData, numVertices) {
    spawnX.push_back(x);
    spawnY.push_back(y);
    spawnZ.push_back(z);
    modelCounter = modelCounter + 1;

}

Model::Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices,
             TextureBuffer *textures, std::string bindOrder) : IndexBuffer(indexData, numIndices), VertexBuffer(vertexData, numVertices){

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

void Model::update() {
    positionMatrix = projectionMatrix * cameraView * modelMatrix;
    this->vBind();
    this->iBind();
    modelMatrixShaderLocation = glGetUniformLocation(barbariaObjectShader.getShaderID(), "modelMatrix");
    glUniformMatrix4fv(modelMatrixShaderLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    this->vUnbind();
    this->iUnbind();
}

Model::~Model() {
    modelCounter = modelCounter - 1;
}