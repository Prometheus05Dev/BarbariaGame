#include "pre.h"

preLoad::preLoad() {
    //Initialize mods from mods.info
    std::ifstream modFile("~/Barbaria/mods.info");
    std::string str;
    if(modFile.fail()){
        std::cout << "[ERROR] File mods.info not existing, this is critical!" << std::endl;
        gameShallClose = true;
    }
    while(std::getline(modFile, str)){
        modNames.push_back(str);
    }
}

void preLoad::loadTextures() {

}
