#include "buffers.h"

VertexBuffer::VertexBuffer(Vertex *data, int numVertices){
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex,x));
    /*glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex,textureX)); */
}
VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &bufferID);
}
void VertexBuffer::vBind(){
    glBindVertexArray(vertexArrayObject);
}
void VertexBuffer::vUnbind(){
    glBindVertexArray(0);
}

IndexBuffer::IndexBuffer(GLuint *data, unsigned int numIndices){
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &bufferID);
}
void IndexBuffer::iBind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}
void IndexBuffer::iUnbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

TextureBuffer::TextureBuffer(const char* texturePath, int pixel){
    stbi_set_flip_vertically_on_load(true);
    textureBuffer = stbi_load(texturePath, &textureWidth, &textureHeight, &bitsPerPixel, 4);
    glGenTextures(1, &bufferID);
    glBindTexture(GL_TEXTURE_2D, bufferID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (pixel == 1){
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    else if (pixel == 0){
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);
}
TextureBuffer::~TextureBuffer(){
    glDeleteTextures(1, &bufferID);
    stbi_image_free(textureBuffer);
}
void TextureBuffer::tBind(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, bufferID);
}
void TextureBuffer::tUnbind(){
    glBindTexture(GL_TEXTURE_2D, 0);
}