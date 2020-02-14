#include "climate_zones.h"

void generateClimateZones(std::vector<std::vector<int>> &climateZones) {
    int x = 0;
    int y = 0;
    std::vector<int> yRow;
    int currentClimate = -100.0f;
    std::vector<std::vector<int>> climate;
    bool getHot = true;
    int tempClimate;
    for(x = 0; x <= 500; x++){
        for(y = 0; y <= 500; y++){
            if(currentClimate == -100.0)
                getHot = true;
            if(currentClimate == 100.0)
                getHot = false;
            if(getHot == true)
                currentClimate = currentClimate + 1;
            if(getHot == false)
                currentClimate = currentClimate - 1;
            //3 = extremely hot 2 = hot 1 = warm 0 = medium -1 = cold -2 = wintery -3 = extremely wintery
            if(currentClimate >= 90 && currentClimate <= 100)
                yRow.push_back(3);
            if(currentClimate >= 65 && currentClimate <= 89)
                yRow.push_back(2);
            if(currentClimate >= 31 && currentClimate <= 64){
                yRow.push_back(1);
            }
            if(currentClimate >= -30 && currentClimate <= 30){
                yRow.push_back(0);
            }
            if(currentClimate >= -63 && currentClimate <= -31){
                yRow.push_back(-1);
            }
            if(currentClimate >= -88 && currentClimate <= -64){
                yRow.push_back(-2);
            }
            if(currentClimate >= -100 && currentClimate <= -89){
                yRow.push_back(-3);
            }
        }
        climateZones.push_back(yRow);
    }
}