#include "python.h"
void load(){
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("testbarbar");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if(pModule != NULL){
        pFunc = PyObject_GetAttrString(pModule, "init");
        pValue = PyObject_CallObject(pFunc, pArgs);
    } else {
        if(PyErr_Occurred())
            PyErr_Print();
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
}