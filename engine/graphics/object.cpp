#include "object.h"

Object::Object(std::string path) {

    modelScene = importer.ReadFile(path, aiProcess_OptimizeMeshes|
                                         aiProcess_OptimizeGraph |
                                         aiProcess_JoinIdenticalVertices |
                                         aiProcess_Triangulate |
                                         aiProcess_ImproveCacheLocality |
                                         aiProcess_CalcTangentSpace |
                                         aiProcess_GenSmoothNormals |
                                         aiProcess_OptimizeMeshes |
                                         aiProcess_OptimizeGraph |
                                         aiProcess_FixInfacingNormals |
                                         aiProcess_ValidateDataStructure | 0


    );

    if(!modelScene){
        std::cout << "Error importing model: " << path << " " << importer.GetErrorString();
    }
    else {
        processData();
    }

    numIndices = indices.size();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normalX));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,textureX));
    glEnableVertexAttribArray(2);
}

bool Object::assimpGetMeshData(const aiMesh *mesh) {
    aiFace *face;
    for(unsigned int v = 0; v < mesh->mNumVertices; v++){
        Vertex vertex;
        vertex.x = mesh->mVertices[v].x;
        vertex.y = mesh->mVertices[v].y;
        vertex.z = mesh->mVertices[v].z;
        vertex.normalX = mesh->mNormals[v].x;
        vertex.normalY = mesh->mNormals[v].y;
        vertex.normalZ = mesh->mNormals[v].z;
        if(mesh->mTextureCoords[0]) {
            vertex.textureX = mesh->mTextureCoords[0][v].x;
            vertex.textureY = mesh->mTextureCoords[0][v].y;
        }else{
            vertex.textureX = 0.0f;
            vertex.textureY = 0.0f;
        }
        vertices.push_back(vertex);
    }
    for(unsigned int f = 0; f < mesh->mNumFaces; f++){
        face = &mesh->mFaces[f];
        indices.push_back(face->mIndices[0]);
        indices.push_back(face->mIndices[1]);
        indices.push_back(face->mIndices[2]);
    }
    return true;
}

bool Object::processData() {
    bool repeat = true;
    nodeBuffer.push_back(modelScene->mRootNode);

    if(modelScene->mNumMeshes > 0){
        for(unsigned int m = 0; m < modelScene->mNumMeshes; m++){
            this->assimpGetMeshData(modelScene->mMeshes[m]);
        }
    }

    while(repeat){
        for(unsigned int a = 0; a < nodeBuffer.size(); a++){
            modelNode = nodeBuffer.at(a);
            if(modelNode->mNumChildren > 0){
                for(unsigned int c = 0; c < modelNode->mNumChildren; c++){
                    nodeBuffer.push_back(modelNode->mChildren[c]);
                }
            }
            else {
                repeat = false;
            }
        }
    }
    for(unsigned int a = 0; a < nodeBuffer.size(); a++){
        modelNode = nodeBuffer.at(a);
        if(modelNode->mNumMeshes > 0){
            for(unsigned int b = 0; b < modelNode->mNumMeshes; b++){
                assimpGetMeshData(modelScene->mMeshes[b]);
            }
        }
    }
}

void Object::bind() {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
}
