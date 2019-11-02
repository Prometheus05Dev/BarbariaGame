#include "loader.h"

std::vector<PythonScript> pythonScripts;

void preInitScript(std::string modName, std::string modPath){
    PythonScript bufferScript;
    bufferScript.preInit(modName, modPath);
    pythonScripts.push_back(bufferScript);
}