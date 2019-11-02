//
// Created by janek on 06.10.19.
//

#ifndef BARBARIACLION_BUFFERS_H
#define BARBARIACLION_BUFFERS_H

#include <ext_decl.h>
#include <GL/glew.h>
#include <iostream>
#include <stb_image.h>

class VertexBuffer{
public:
    VertexBuffer(Vertex *data, int numVertices);
    void vBind();
    void vUnbind();
protected:
    GLuint bufferID;
    GLuint vertexArrayObject;
private:
};

class IndexBuffer{
public:
    IndexBuffer(GLuint *data, unsigned int numVertices);
    void iBind();
    void iUnbind();
protected:
    GLuint bufferID;
private:
};

class TextureBuffer{
public:
    TextureBuffer(const char* texturePath, int pixel);
    void tBind();
    void tUnbind();
    unsigned int getTextureReference();
protected:
    GLuint bufferID;
    int textureWidth;
    int textureHeight;
    int bitsPerPixel;
    stbi_uc *textureBuffer;
private:
};

#endif //BARBARIACLION_BUFFERS_H
