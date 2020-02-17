#include "world.h"

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
    for(int x = 0; x <= 2; x++){
        for(int y = 0; y <= 2; y++){
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
            if(climateZones[x][y] == 3){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.extremelyHotBiomes.begin(), mainLoader.extremelyHotBiomes.end());
                    tempChunk = new Chunk(mainLoader.extremelyHotBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.extremelyHotBiomes[0]);
                }
            }
            if(climateZones[x][y] == 2){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.hotBiomes.begin(), mainLoader.hotBiomes.end());
                    tempChunk = new Chunk(mainLoader.hotBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.hotBiomes[0]);
                }
            }
            if(climateZones[x][y] == 1){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.warmBiomes.begin(), mainLoader.warmBiomes.end());
                    tempChunk = new Chunk(mainLoader.warmBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.warmBiomes[0]);
                }
            }
            if(climateZones[x][y] == 0){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.mediumBiomes.begin(), mainLoader.mediumBiomes.end());
                    tempChunk = new Chunk(mainLoader.mediumBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.mediumBiomes[0]);
                }
            }
            if(climateZones[x][y] == -1){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.coldBiomes.begin(), mainLoader.coldBiomes.end());
                    tempChunk = new Chunk(mainLoader.coldBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.coldBiomes[0]);
                }
            }
            if(climateZones[x][y] == -2){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.winteryBiomes.begin(), mainLoader.winteryBiomes.end());
                    tempChunk = new Chunk(mainLoader.winteryBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.winteryBiomes[0]);
                }
            }
            if(climateZones[x][y] == -3){
                if(dist6(rng) == 3) {
                    std::random_shuffle(mainLoader.extremelyWinteryBiomes.begin(),mainLoader.extremelyWinteryBiomes.end());
                    tempChunk = new Chunk(mainLoader.extremelyWinteryBiomes[0]);
                }
                else {
                    tempChunk = new Chunk(mainLoader.extremelyWinteryBiomes[0]);
                }
            }
            yChunks.push_back(*tempChunk);
        }
        worldChunks.push_back(yChunks);
        yChunks.erase(yChunks.begin(), yChunks.end());
    }
}
