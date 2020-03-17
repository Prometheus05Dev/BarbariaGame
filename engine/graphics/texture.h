#ifndef BARBARIA_TEXTURE_H
#define BARBARIA_TEXTURE_H
#include <stb_image.h>
#include <GL/glew.h>

class Texture {
public:
    Texture(const char *texturePath);
    void bind();
    void unbind();
    ~Texture();
protected:
private:
    GLuint bufferID;
    int textureWidth;
    int textureHeight;
    int bitsPerPixel;
    stbi_uc *textureBuffer;
};

#endif //BARBARIA_TEXTURE_H
