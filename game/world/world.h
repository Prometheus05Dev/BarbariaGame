#ifndef BARBARIA_WORLD_H
#define BARBARIA_WORLD_H

#include <vector>
#include <algorithm>
#include <random>
#include "generation/climate_zones.h"
#include "../../api/loader.h"
#include "world/chunk.h"

class World {
public:
    World();
protected:
private:
    std::vector<std::vector<int>> climateZones;
    std::vector<std::vector<Chunk>> worldChunks;
    Loader mainLoader;
};

#endif //BARBARIA_WORLD_H
