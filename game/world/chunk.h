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
    std::vector<Block> blockList = {};
    std::vector<GrowingBlock> growingBlockList = {};
    float x = 0;
    float y = 0;
    float z = 0;
};

#endif //BARBARIACLION_CHUNK_H
