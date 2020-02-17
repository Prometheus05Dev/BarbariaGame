#ifndef BARBARIA_EXTERN_WORLD_H
#define BARBARIA_EXTERN_WORLD_H

#include "game/world/world.h"

extern World& returnMainWorld();

World& returnMainWorld(){
    static World mainWorld = World();
    return mainWorld;
}

#endif //BARBARIA_EXTERN_WORLD_H
