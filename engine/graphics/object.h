#ifndef BARBARIA_OBJECT_H
#define BARBARIA_OBJECT_H

#include <GL/glew.h>
#include <vector>
#include <string>
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>
#include <matrix4x4.h>
#include <cimport.h>
#include <iostream>

struct Vertex {
    float x, y, z;
    float normalX, normalY, normalZ;
};

class Object {
public:
    Object(std::string path);
    bool processData();
    bool assimpGetMeshData(const aiMesh *mesh);
    void bind();
protected:
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int numIndices = 0;
    std::vector<const aiNode*> nodeBuffer;
    unsigned int numNodeBuffers;
    Assimp::Importer importer;
    const aiScene *modelScene;
    const aiNode *modelNode;
    const aiMesh *modelMesh;
    const aiFace *modelFace;
};


#endif //BARBARIA_OBJECT_H
