#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[55];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_main_internal;
extern CPyModule *CPyModule_main;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_requests;
extern tuple_T2OO CPyDef_get_coordinates(PyObject *cpy_r_city, PyObject *cpy_r_api_key);
extern PyObject *CPyPy_get_coordinates(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_get_weather(double cpy_r_lat, double cpy_r_lon, PyObject *cpy_r_api_key);
extern PyObject *CPyPy_get_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern tuple_T3OOO CPyDef_determine_emojis(PyObject *cpy_r_weather_data);
extern PyObject *CPyPy_determine_emojis(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_main(void);
extern PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_display_weather(PyObject *cpy_r_lat, PyObject *cpy_r_lon, PyObject *cpy_r_api_key);
extern PyObject *CPyPy_display_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
