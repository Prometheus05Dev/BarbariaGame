#ifndef BARBARIACLION_PRE_H
#define BARBARIACLION_PRE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <filesystem>
#include <ext_decl.h>
#include <core/buffers.h>
#include <loader.h>

class preLoad{
public:
    preLoad();
    std::vector<std::string> getModNames();
    int getModCount();
    void printMods();
    void loadTextures();
    void loadScripts(std::string modPath);
protected:
    std::vector<std::vector<int>> textures; //Two-Dimensional Array, Lines: Reference to Texture Instance Rows: String(configured name)
    std::vector<std::string> modNames;
    int modCount = 0;
private:
};

#endif //BARBARIACLION_PRE_H
