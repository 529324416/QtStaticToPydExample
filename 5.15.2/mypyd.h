#ifndef TESTDLL_H
#define TESTDLL_H
#include "mypyd_global.h"
#include <Python.h>

TESTDLLSHARED_EXPORT PyObject* test(PyObject* self, PyObject* args);
TESTDLLSHARED_EXPORT PyObject* RunWindow(PyObject* self, PyObject* args);

#endif // TESTDLL_H