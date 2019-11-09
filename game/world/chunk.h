#ifndef BARBARIACLION_CHUNK_H
#define BARBARIACLION_CHUNK_H

#include <vector>
#include <random>
#include <entity/mob.h>
#include <entity/player.h>
#include "block.h"

class Chunk{
public:
    Chunk(float x, float y, float z);
    void read();
    void save();
    void update();
protected:
    std::vector<Mob> mobList = {};
    std::vector<Player> playerList = {};
    std::vector<std::vector<int>> heightMap = {};
    std::vector<Vertex> vertices = {};
    Model terrain;
    float x = 0;
    float y = 0;
    float z = 0;
    float currentTextureX;
    float currentTextureY;
    int numberPerX = 15;
    int numberPerY = 15;
    int indexCount = 0;
    std::vector<GLuint> indices = {};
};

#endif //BARBARIACLION_CHUNK_H
