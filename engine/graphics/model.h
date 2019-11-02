#ifndef BARBARIACLION_MODEL_H
#define BARBARIACLION_MODEL_H

#include <core/buffers.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ext_decl.h>

class Model : public VertexBuffer, IndexBuffer{
public:
    Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices);
    Model(float x, float y, float z, Vertex *vertexData, int numVertices, GLuint *indexData, int numIndices, TextureBuffer *textures, std::string bindOrder);
    void spawn();
    void transform(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degrees, float x, float y, float z);
    void update();
    ~Model();
protected:
    static std::vector<float> spawnX;
    static std::vector<float> spawnY;
    static std::vector<float> spawnZ;
    static int modelCounter;
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    float screenAspect = (float)screenWidth / (float)screenHeight;
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), screenAspect, 0.1f, 100.0f);
    int myNumber = 0;
};

#endif //BARBARIACLION_MODEL_H
