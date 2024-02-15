#ifndef TESTDLL_GLOBAL_H
#define TESTDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTDLL_LIBRARY)
#  define TESTDLLSHARED_EXPORT __declspec(dllexport)
#else
#  define TESTDLLSHARED_EXPORT __declspec(dllimport)
#endif

#endif // TESTDLL_GLOBAL_H
