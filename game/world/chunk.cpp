#include "chunk.h"

Chunk::Chunk(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;

}

void Chunk::read() {
    //Fill Vertices
    for(int i = 0; i <= 15; i++){
        for(int j = 0; i<=15; i++){
            if(j == 0 || j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14){
                currentTextureY = 0.0;
            }
            if(j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11 || j == 13 || j == 15) {
                currentTextureY = 1.0f;
            }
            if(i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14){
                currentTextureX = 0.0;
            }
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15) {
                currentTextureX = 1.0f;
            }
            Vertex bufferVertex = {static_cast<float>(i), static_cast<float>(j), static_cast<float>(heightMap[i][j]), currentTextureX, currentTextureY};
            vertices.push_back(bufferVertex);
        }
    }

    //Fill indices
    for(indexCount = 0; indexCount <= numberPerY * numberPerX - numberPerY; indexCount++){
        GLuint firstIndexBuffer = indexCount;
        GLuint secondIndexBuffer = indexCount + 1;
        GLuint thirdIndexBuffer = indexCount + numberPerY;
        GLuint fourthIndexBuffer = indexCount + numberPerY - 1;
        indices.push_back(firstIndexBuffer);
        indices.push_back(secondIndexBuffer);
        indices.push_back(thirdIndexBuffer);
        indices.push_back(fourthIndexBuffer);
    }

    //Convert std::vectors to arrays
    Vertex* verticesArray = &vertices[0];
    GLuint* indexArrays = &indices[0];

    //Fill the terrain model
    terrain = Model(x, y, z, verticesArray, numberPerY * numberPerX, indexArrays, indexCount);
}

void Chunk::update() {

}
