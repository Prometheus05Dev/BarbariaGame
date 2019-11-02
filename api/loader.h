#ifndef BARBARIACLION_LOADER_H
#define BARBARIACLION_LOADER_H

#include <python/python.h>
#include <vector>

extern void preInitScript(std::string modName, std::string modPath);
extern void loopScripts();
extern void postInitScripts();

#endif //BARBARIACLION_LOADER_H
