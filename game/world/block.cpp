#include "block.h"

Block::Block(float x, float y, float z, TextureBuffer backTexture, TextureBuffer frontTexture, TextureBuffer rightTexture,
             TextureBuffer leftTexture, TextureBuffer bottomTexture, TextureBuffer topTexture)
        : backTexture(backTexture), frontTexture(frontTexture), rightTexture(rightTexture), leftTexture(leftTexture),
          bottomTexture(bottomTexture), topTexture(topTexture) {

    this->x = x;
    this->y = y;
    this->z = z;

    this->transform(x, y, z);

}

void Block::transform(float x, float y, float z) {
    backPlane.transform(x, y, z);
    frontPlane.transform(x, y, z);
    rightPlane.transform(x, y, z);
    leftPlane.transform(x, y, z);
    bottomPlane.transform(x, y, z);
    topPlane.transform(x, y, z);
}

void Block::scale(float x, float y, float z) {
    backPlane.scale(x, y, z);
    frontPlane.scale(x, y, z);
    rightPlane.scale(x, y, z);
    leftPlane.scale(x, y, z);
    bottomPlane.scale(x, y, z);
    topPlane.scale(x, y, z);
}

void Block::rotate(float degrees, float x, float y, float z) {
    backPlane.rotate(degrees, x, y, z);
    frontPlane.rotate(degrees, x, y, z);
    rightPlane.rotate(degrees, x, y, z);
    leftPlane.rotate(degrees, x, y, z);
    bottomPlane.rotate(degrees, x, y, z);
    topPlane.rotate(degrees, x, y, z);
}