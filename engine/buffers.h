#pragma once
#include <GL/glew.h>
#include <stddef.h>
#include <stb_image.h>
#include <iostream>
//new
struct Vertex{
    float x;
    float y;
    float z;
};

class VertexBuffer {
public:
    VertexBuffer(Vertex* data, int numVertices);
    virtual ~VertexBuffer();
    void vBind();
    void vUnbind();
private:
    GLuint bufferID;
    GLuint vertexArrayObject;
};

class IndexBuffer {
public:
    IndexBuffer(GLuint* data, unsigned int numIndices);
    virtual ~IndexBuffer();
    void iBind();
    void iUnbind();
protected:
    int numIndices;
private:
    GLuint bufferID;
};
struct TextureBuffer {
    TextureBuffer(const char* texturePath, int pixel);
    virtual ~TextureBuffer();
    void tBind();
    void tUnbind();
private:
    GLuint vertexArrayObject;
    GLuint bufferID;
    int textureWidth;
    int textureHeight;
    int bitsPerPixel;
    stbi_uc *textureBuffer;
};
