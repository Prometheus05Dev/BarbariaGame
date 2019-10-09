#ifndef BARBARIACLION_PRE_H
#define BARBARIACLION_PRE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <utils/declarations.h>
#include "pre.h"

class preLoad{
public:
    preLoad();
    void loadTextures();
protected:
    std::vector<std::vector<int>> textures; //Two-Dimensional Array, Lines: Reference to Texture Instance Rows: String(configured name)
    std::vector<std::string> modNames;
private:
};

#endif //BARBARIACLION_PRE_H
