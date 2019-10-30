#include "python.h"

void PythonScript::preInit(){
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("barbaria");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if(pModule != NULL){
        pFunc = PyObject_GetAttrString(pModule, "pre");
        pValue = PyObject_CallObject(pFunc, pArgs);
    } else {
        if(PyErr_Occurred())
            PyErr_Print();
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
}

void PythonScript::loop() {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("barbaria");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if(pModule != NULL){
        pFunc = PyObject_GetAttrString(pModule, "loop");
        pValue = PyObject_CallObject(pFunc, pArgs);
    } else {
        if(PyErr_Occurred())
            PyErr_Print();
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
}

void PythonScript::postInit() {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("barbaria");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if(pModule != NULL){
        pFunc = PyObject_GetAttrString(pModule, "postInit");
        pValue = PyObject_CallObject(pFunc, pArgs);
    } else {
        if(PyErr_Occurred())
            PyErr_Print();
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
}