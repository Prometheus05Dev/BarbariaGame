#ifndef BARBARIACLION_PYTHON_H
#define BARBARIACLION_PYTHON_H

#define PY_SSIZE_T_CLEAN

#include <python3.7m/Python.h>
#include <iostream>

class PythonScript{
public:
    void preInit(std::string scriptName, std::string scriptPath);
    void loop();
    void postInit();
};

#endif
