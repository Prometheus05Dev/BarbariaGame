#include "python.h"

static PyObject*
barbaria_helloWorld(PyObject *self, PyObject *args){
        std::cout << "Hello World!" << std::endl;
        return PyLong_FromLong(3);
}

static PyMethodDef BarbariaMethods[] = {
        {"helloWorld", barbaria_helloWorld, METH_VARARGS,
         "Hello World for testing purposes!"},
        {NULL, NULL, 0, NULL}
};

static PyModuleDef BarbariaModule = {
        PyModuleDef_HEAD_INIT, "barbariapy", NULL, -1, BarbariaMethods,
        NULL, NULL, NULL, NULL
};

static PyObject*
PyInit_barbaria(void){
    return PyModule_Create(&BarbariaModule);
}

void PythonScript::preInit(std::string scriptName, std::string scriptPath){
    const char *scriptNamePY = scriptName.c_str();
    const char* scriptPathPY = scriptPath.c_str();
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs;
    PyImport_AppendInittab("barbariapy", &PyInit_barbaria);
    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("barbaria");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    pFunc = PyObject_GetAttrString(pModule, "pre");
    if(PyCallable_Check(pFunc))
        PyObject_CallObject(pFunc, NULL);
    Py_DECREF(pModule);
    Py_DECREF(pName);
    Py_Finalize();
    return;
}

void PythonScript::loop() {
}

void PythonScript::postInit() {

}