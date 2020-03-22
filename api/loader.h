#ifndef BARBARIA_LOADER_H
#define BARBARIA_LOADER_H

#include "../engine/graphics/shader.h"
#include "../engine/graphics/camera.h"
#include <string>
#include <filesystem>
#include <pwd.h>
#include <zconf.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <engine/graphics/texture.h>
#include <engine/graphics/object.h>

struct ObjectConfig {
    std::string name;
    int textureID;
    int modelID;
};

class Loader {
public:
    Loader();
    void loadBiomes();
    void loadModels();
    void loadObjects();
    void loadTextures();
    Shader loadShader();
    std::vector<std::string> extremelyHotBiomes;
    std::vector<std::string> hotBiomes;
    std::vector<std::string> warmBiomes;
    std::vector<std::string> mediumBiomes;
    std::vector<std::string> coldBiomes;
    std::vector<std::string> winteryBiomes;
    std::vector<std::string> extremelyWinteryBiomes;
protected:
private:
    std::string configDirectory = "";
    std::vector<std::string> biomeList;
    std::vector<int> biomeClimates;
    std::vector<ObjectConfig> models;
    std::vector<Texture> textures;
    std::vector<Object> objects;
};

#endif //BARBARIA_LOADER_H
