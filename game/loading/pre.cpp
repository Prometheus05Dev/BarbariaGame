#include "pre.h"

preLoad::preLoad() {
    //Initialize mods from mods.info
    std::string filePath = "../resources/mods.info";
    std::ifstream modFile(filePath.c_str(), std::ios::in);
    std::string str;
    if(!modFile){
        std::cerr << "[ERROR] File mods.info couldn't be opened, this is critical!" << std::endl;
        std::cerr << "[ERROR] " << std::strerror(errno) << std::endl;
        gameShallClose = true;
    }
    while(std::getline(modFile, str)){
        modCount = modCount + 1;
        modNames.push_back(str);
    }
    loadScripts("../resources/scripts");
}

std::vector<std::string> preLoad::getModNames() {
    return modNames;
}

int preLoad::getModCount() {
    return modCount;
}

void preLoad::printMods() {
    for(std::string i : modNames){
        std::cout << "[INFO] Mod registered: " << i << std::endl;
    }
}


void preLoad::loadScripts(std::string modPath){
    namespace fileSystem = std::filesystem;
    fileSystem::path relativeModPath = modPath;
    fileSystem::path absoluteModPath = fileSystem::absolute(relativeModPath);
    std::string absoluteModPathString = absoluteModPath.u8string();
    for(std::string i : modNames){
        preInitScript(i, modPath);
    }
}

void preLoad::loadTextures() {
    namespace fileSystem = std::filesystem;
    std::string j;
    for(int counter = 0; counter <= 1; counter++){
        for(std::string i : modNames){
            if(counter == 1){
                j = "entities";
                std::cout << "[INFO] Loading entity textures" << std::endl;
            }
            else{
                j = "blocks";
                std::cout << "[INFO] Loading block textures" << std::endl;
            }
            std::string filePath = "../resources/textures/" + i + "/" + j + "/";
            for(const auto & file : fileSystem::directory_iterator(filePath)){
                std::cout << "[INFO] Texture file of mod " << i << " has been registered " << file.path() << std::endl;
                TextureBuffer bufferForVertexData(file.path().c_str(), 1);
            }
        }
    }
}

