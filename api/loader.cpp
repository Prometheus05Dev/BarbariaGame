#include "loader.h"

Loader::Loader() {
    //Load Linux config path
    passwd *pw = getpwuid(getuid());
    std::string configPath = std::string(pw->pw_dir);
    configPath += "/.config/barbaria";
    configDirectory = configPath;
    loadBiomes();
}

void Loader::loadBiomes() {
    //Get biomes path
    std::string biomesDirectory = "";
    biomesDirectory = configDirectory + "/biomes/";

    //Get all files and their content, push them back to biomesList
    for (const auto & entry : std::filesystem::directory_iterator(biomesDirectory)) {
        std::ifstream biomeFile(entry.path());
        std::string line;
        int iterator = 0;
        while(std::getline(biomeFile, line)){
            if(iterator == 0)
                biomeList.push_back(line);
            if(iterator == 1)
                biomeClimates.push_back(std::stoi(line));
            iterator = iterator + 1;
        }
    }

    //Print registered biomes to console
    for(int it = 0; it < biomeList.size(); it++) {
        std::cout << "Registering Biome: " << biomeList[it] << " with climate: " << biomeClimates[it] << std::endl;
    }

    //Sort biomes to their climate
    for(int it = 0; it < biomeClimates.size(); it++){
        if(biomeClimates[it] == 3){
            extremelyHotBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == 2){
            hotBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == 1){
            warmBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == 0){
            mediumBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == -1){
            coldBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == -2){
            winteryBiomes.push_back(biomeList[it]);
        }
        if(biomeClimates[it] == -3){
            extremelyWinteryBiomes.push_back(biomeList[it]);
        }
    }
}