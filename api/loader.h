#ifndef BARBARIA_LOADER_H
#define BARBARIA_LOADER_H

#include "../engine/graphics/shader.h"
#include <string>
#include <filesystem>
#include <pwd.h>
#include <zconf.h>
#include <iostream>
#include <vector>
#include <fstream>

class Loader {
public:
    Loader();
    void loadBiomes();
    void loadShader();
    std::vector<std::string> extremelyHotBiomes;
    std::vector<std::string> hotBiomes;
    std::vector<std::string> warmBiomes;
    std::vector<std::string> mediumBiomes;
    std::vector<std::string> coldBiomes;
    std::vector<std::string> winteryBiomes;
    std::vector<std::string> extremelyWinteryBiomes;
    Shader *mainShader;
protected:
private:
    std::string configDirectory = "";
    std::vector<std::string> biomeList;
    std::vector<int> biomeClimates;
};

#endif //BARBARIA_LOADER_H
