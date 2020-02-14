#include "climate_zones.h"
void generateClimateZones(std::vector<std::vector<int>> &climateZones) {
    int x = 0;
    int y = 0;
    std::vector<int> yRow;
    int currentClimate = -100.0f;
    std::vector<std::vector<int>> climate;
    bool getHot = true;
    int tempClimate;
    for(x = 0; x <= 1000; x++){
        for(y = 0; y <= 1000; y++){

            if(currentClimate == -100.0)
                getHot = true;
            else if(currentClimate == 100.0)
                getHot = false;

            if(getHot)
                currentClimate++;
            else
                currentClimate--;
            //3 = extremely hot 2 = hot 1 = warm 0 = medium -1 = cold -2 = wintery -3 = extremely wintery
            if(currentClimate >= 90 && currentClimate <= 100)
                yRow.push_back(3);
            else if(currentClimate >= 65 && currentClimate <= 89)
                yRow.push_back(2);
            else if(currentClimate >= 31 && currentClimate <= 64){
                yRow.push_back(1);
            }
            else if(currentClimate >= -30 && currentClimate <= 30){
                yRow.push_back(0);
            }
            else if(currentClimate >= -63 && currentClimate <= -31){
                yRow.push_back(-1);
            }
            else if(currentClimate >= -88 && currentClimate <= -64){
                yRow.push_back(-2);
            }
            else if(currentClimate >= -100 && currentClimate <= -89){
                yRow.push_back(-3);
            } else {
                std::cout << "[climate_zones.cpp]: Fatal error! currentClimate zone not in range. Aborting" << std::endl;
                std::cout << "Climate zone is:"+std::to_string(currentClimate) << std::endl;
                exit(42);
            }
        }
        climateZones.push_back(yRow);
    }
}