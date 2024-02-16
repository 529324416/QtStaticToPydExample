#include <stdio.h>
#include <Python.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "mypyd.h"

PyObject* test(PyObject* self, PyObject* args){
    printf("Hello World!!\n");
    Py_RETURN_NONE;
}

PyObject* RunWindow(PyObject* self, PyObject* args){

    int argc;
    char** argv;
    if (!PyArg_ParseTuple(args, "iO", &argc, &argv)){
        printf("invalid arguments\n");
        return NULL;
    }
    QApplication app(argc, argv);
    QWidget window;
    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.show();
    int ret = app.exec();
    return Py_BuildValue("i", ret);
}


static PyMethodDef SpamMethods[] = {
    {"RunWindow", RunWindow, METH_VARARGS, "invoke a qt5 window"},
    {"test", test, METH_VARARGS, "output 'hello world'"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "mypyd",    /* name of module */
    "",         /* module documentation, may be NULL */
    -1,         /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};
/* Module initialization function called at "import example"*/
PyMODINIT_FUNC PyInit_mypyd(void){
    return PyModule_Create(&spammodule);
}