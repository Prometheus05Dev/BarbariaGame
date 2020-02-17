#ifndef BARBARIA_WORLD_H
#define BARBARIA_WORLD_H

#include "../../api/loader.h"
#include <vector>
#include <algorithm>
#include <random>
#include "generation/climate_zones.h"
#include "world/chunk.h"
#include "../utils/time.h"
#include "../camera/camera.h"

class World {
public:
    World();
    Loader mainLoader;
    GameTime mainTick;
    Camera mainCamera;
protected:
private:
    std::vector<std::vector<int>> climateZones;
    std::vector<std::vector<Chunk>> worldChunks;
};

#endif //BARBARIA_WORLD_H
