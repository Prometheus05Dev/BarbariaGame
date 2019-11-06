#include "chunk.h"

Chunk::Chunk(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Chunk::update() {
    //Changing the growth of plants.
    for(GrowingBlock &growingBlock : growingBlockList){
        std::random_device randomDeviceNumber;
        std::mt19937 randomSeed(randomDeviceNumber()); // seed the generator
        std::uniform_int_distribution<> range(1, 100);
        int randomNumber = range(randomSeed);
        if(randomNumber == 17){
            growingBlock.stage = growingBlock.stage + 1;
        }
    }
}
