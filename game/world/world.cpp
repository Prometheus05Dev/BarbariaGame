#include "world.h"
#include "random"
#include "unistd.h"

World::World() {
    generateClimateZones(climateZones);
    std::string lastExtremelyHot;
    std::string lastHot;
    std::string lastWarm;
    std::string lastMedium;
    std::string lastCold;
    std::string lastWinterly;
    std::string lastExtremelyWinterly;
    std::vector<Chunk> yChunks;
    Chunk *tempChunk;
    srand(time(nullptr));
    int dist6;
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            dist6 = rand()%6;
            if (climateZones[x][y] == 3) {
                if (dist6 == 3) {
                    //std::random_shuffle(mainLoader.extremelyHotBiomes.begin(), mainLoader.extremelyHotBiomes.end());

                    tempChunk = new Chunk(mainLoader.extremelyHotBiomes[rand() % mainLoader.extremelyHotBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.extremelyHotBiomes[0]);
                }
            }
            else if(climateZones[x][y] == 2) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.hotBiomes.begin(), mainLoader.hotBiomes.end());
                    tempChunk = new Chunk(mainLoader.hotBiomes[rand() % mainLoader.hotBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.hotBiomes[0]);
                }
            }
            else if(climateZones[x][y] == 1) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.warmBiomes.begin(), mainLoader.warmBiomes.end());
                    tempChunk = new Chunk(mainLoader.warmBiomes[rand() % mainLoader.warmBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.warmBiomes[0]);
                }
            }
            else if(climateZones[x][y] == 0) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.mediumBiomes.begin(), mainLoader.mediumBiomes.end());
                    tempChunk = new Chunk(mainLoader.mediumBiomes[rand() % mainLoader.mediumBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.mediumBiomes[0]);
                }
            }
            else if(climateZones[x][y] == -1) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.coldBiomes.begin(), mainLoader.coldBiomes.end());
                    tempChunk = new Chunk(mainLoader.coldBiomes[rand() % mainLoader.coldBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.coldBiomes[0]);
                }
            }
            else if(climateZones[x][y] == -2) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.winteryBiomes.begin(), mainLoader.winteryBiomes.end());
                    tempChunk = new Chunk(mainLoader.winteryBiomes[rand() % mainLoader.winteryBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.winteryBiomes[0]);
                }
            }
            else if(climateZones[x][y] == -3) {
                if (dist6 == 3) {
//                    std::random_shuffle(mainLoader.extremelyWinteryBiomes.begin(),mainLoader.extremelyWinteryBiomes.end());
                    tempChunk = new Chunk(
                            mainLoader.extremelyWinteryBiomes[rand() % mainLoader.extremelyWinteryBiomes.size()]);
                } else {
                    tempChunk = new Chunk(mainLoader.extremelyWinteryBiomes[0]);
                }
            } else {
                std::cout << "Fatal error! Climate zone not in range. Aborting" << std::endl;
                exit(-1);
            }
            yChunks.push_back(*tempChunk);
        }
        worldChunks.push_back(yChunks);
    }
}
