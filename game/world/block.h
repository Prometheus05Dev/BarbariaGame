#ifndef BARBARIACLION_BLOCK_H
#define BARBARIACLION_BLOCK_H


#include <core/buffers.h>
#include <graphics/model.h>

class Block {
public:
    Block(float x, float y, float z, TextureBuffer backTexture, TextureBuffer frontTexture, TextureBuffer rightTexture,
          TextureBuffer leftTexture, TextureBuffer bottomTexture, TextureBuffer topTexture);
    void update();
    void destroy();
    void transform(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degrees, float x, float y, float z);
    ~Block();
    TextureBuffer topTexture;
    TextureBuffer bottomTexture;
    TextureBuffer leftTexture;
    TextureBuffer rightTexture;
    TextureBuffer frontTexture;
    TextureBuffer backTexture;
protected:

    //All the Vertex data for a typical block(special ones will be a blender model)

    Vertex BlockStructureFront[5] = {
            Vertex{-0.5f, -0.5f, 0.0f, 0.0f, 0.0f}, //0 Left Down
            Vertex{0.5f, -0.5f, 0.0f, 1.0f, 0.0f}, //1 Right Down
            Vertex{-0.5f, 0.5f, 0.0f, 0.0f, 1.0f}, //2 Left Upper
            Vertex{0.5f, 0.5f, 0.0f, 1.0f, 1.0f} //3 Right Upper
    };
    Vertex BlockStructureTop[5] = {
            Vertex{-0.5f, 0.5f, 0.0f, 0.0f, 0.0f}, //2 Left Upper //0
            Vertex{0.5f, 0.5f, 0.0f, 1.0f, 0.0f}, //3 Right Upper //1
            Vertex{-0.5f, 0.5f, 1.0f, 0.0f, 1.0f}, //6 Left Upper Back //2
            Vertex{0.5f, 0.5f, 1.0f, 1.0f, 1.0f}  //7 Right Upper Back //3
    };
    Vertex BlockStructureRight[5] = {
            Vertex{0.5f, -0.5f, 0.0f, 0.0f, 0.0f}, //1 Right Down //0
            Vertex{0.5f, 0.5f, 0.0f, 0.0f, 1.0f}, //3 Right Upper // 1
            Vertex{0.5f, 0.5f, 1.0f, 1.0f, 1.0f},  //7 Right Upper Back //2
            Vertex{0.5f, -0.5f, 1.0f, 1.0f, 0.0f} //5 Right Down Back //3
    };
    Vertex BlockStructureBottom[5] = {
            Vertex{-0.5f, -0.5f, 0.0f, 0.0f, 0.0f}, //0 Left Down //0
            Vertex{0.5f, -0.5f, 0.0f, 1.0f, 0.0f}, //1 Right Down //1
            Vertex{-0.5f, -0.5f, 1.0f, 0.0f, 1.0f}, //4 Left Down Back //2
            Vertex{0.5f, -0.5f, 1.0f, 1.0f, 1.0f} //5 Right Down Back //3
    };
    Vertex BlockStructureBack[5] = {
            Vertex{-0.5f, -0.5f, 1.0f, 0.0f, 0.0f}, //4 Left Down Back //0
            Vertex{0.5f, -0.5f, 1.0f, 1.0f, 0.0f}, //5 Right Down Back //1
            Vertex{0.5f, 0.5f, 1.0f, 1.0f, 1.0f},  //7 Right Upper Back //2
            Vertex{-0.5f, 0.5f, 1.0f, 0.0f, 1.0f} //6 Left Upper Back //3
    };
    Vertex BlockStructureLeft[5] = {
            Vertex{-0.5f, -0.5f, 0.0f, 0.0f, 0.0f}, //0 Left Down //0
            Vertex{-0.5f, -0.5f, 1.0f, 1.0f, 0.0f}, //4 Left Down Back //1
            Vertex{-0.5f, 0.5f, 1.0f, 1.0f, 1.0f}, //6 Left Upper Back //2
            Vertex{-0.5f, 0.5f, 0.0f, 0.0f, 1.0f} //2 Left Upper //3
    };

    //Default Indices

    GLuint BlockStructureFrontIndices[7] = {
            0, 1, 2,
            2, 3, 1
    };
    GLuint BlockStructureTopIndices[7] = {
            0, 1, 2,
            2, 3, 1
    };
    GLuint BlockStructureRightIndices[7] = {
            0, 1, 2,
            0, 3, 2
    };
    GLuint BlockStructureBottomIndices[7] = {
            0, 1, 2,
            2, 3, 1,
    };
    GLuint BlockStructureBackIndices[7] = {
            0, 1, 2,
            0, 3, 2
    };
    GLuint BlockStructureLeftIndices[7] = {
            0, 1, 2,
            0, 3, 2
    };

    float x = 0;
    float y = 0;
    float z = 0;

    Model backPlane = Model(x, y, z, BlockStructureBack, 4, BlockStructureBackIndices, 6);
    Model frontPlane = Model(x, y, z, BlockStructureFront, 4, BlockStructureFrontIndices, 6);
    Model rightPlane = Model(x, y, z, BlockStructureRight, 4, BlockStructureRightIndices, 6);
    Model leftPlane = Model(x, y, z, BlockStructureLeft, 4, BlockStructureLeftIndices, 6);
    Model bottomPlane = Model(x, y, z, BlockStructureBottom, 4, BlockStructureBottomIndices, 6);
    Model topPlane = Model(x, y, z, BlockStructureTop, 4, BlockStructureTopIndices, 6);

};

#endif //BARBARIACLION_BLOCK_H
