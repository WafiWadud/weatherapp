#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"get_coordinates", (PyCFunction)CPyPy_get_coordinates, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_weather", (PyCFunction)CPyPy_get_weather, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"determine_emojis", (PyCFunction)CPyPy_determine_emojis, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"main", (PyCFunction)CPyPy_main, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"display_weather", (PyCFunction)CPyPy_display_weather, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "main",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_main(void)
{
    PyObject* modname = NULL;
    if (CPyModule_main_internal) {
        Py_INCREF(CPyModule_main_internal);
        return CPyModule_main_internal;
    }
    CPyModule_main_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_main_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_main_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_main_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_main_internal;
    fail:
    Py_CLEAR(CPyModule_main_internal);
    Py_CLEAR(modname);
    return NULL;
}

tuple_T2OO CPyDef_get_coordinates(PyObject *cpy_r_city, PyObject *cpy_r_api_key) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    int32_t cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    tuple_T2OO cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    tuple_T2OO cpy_r_r38;
    tuple_T2CC cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    tuple_T2OO cpy_r_r42;
    tuple_T2OO cpy_r_r43;
    cpy_r_r0 = CPyStatics[3]; /* 'http://api.openweathermap.org/geo/1.0/direct' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[4]; /* 'q' */
    cpy_r_r2 = CPyStatics[5]; /* '{:{}}' */
    cpy_r_r3 = CPyStatics[6]; /* '' */
    cpy_r_r4 = CPyStatics[7]; /* 'format' */
    PyObject *cpy_r_r5[3] = {cpy_r_r2, cpy_r_city, cpy_r_r3};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 7, CPyStatic_globals);
        goto CPyL17;
    }
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("main.py", "get_coordinates", 7, CPyStatic_globals, "str", cpy_r_r7);
        goto CPyL17;
    }
    cpy_r_r9 = CPyStatics[8]; /* 'limit' */
    cpy_r_r10 = CPyStatics[9]; /* 'appid' */
    cpy_r_r11 = CPyStatics[49]; /* 1 */
    cpy_r_r12 = CPyDict_Build(3, cpy_r_r1, cpy_r_r8, cpy_r_r9, cpy_r_r11, cpy_r_r10, cpy_r_api_key);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 7, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r13 = CPyModule_requests;
    cpy_r_r14 = CPyStatics[10]; /* 'get' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 8, CPyStatic_globals);
        goto CPyL18;
    }
    PyObject *cpy_r_r16[2] = {cpy_r_r0, cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = CPyStatics[51]; /* ('params',) */
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, cpy_r_r18);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 8, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r20 = CPyStatics[12]; /* 'json' */
    PyObject *cpy_r_r21[1] = {cpy_r_r19};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 9, CPyStatic_globals);
        goto CPyL19;
    }
    CPy_DECREF(cpy_r_r19);
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = PyObject_IsTrue(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r25 = cpy_r_r24 >= 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("main.py", "get_coordinates", 9, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r26 = cpy_r_r24;
    if (!cpy_r_r26) goto CPyL21;
    cpy_r_r27 = CPyStatics[50]; /* 0 */
    cpy_r_r28 = PyObject_GetItem(cpy_r_r23, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 10, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r29 = CPyStatics[13]; /* 'lat' */
    cpy_r_r30 = PyObject_GetItem(cpy_r_r28, cpy_r_r29);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 10, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r31 = CPyStatics[50]; /* 0 */
    cpy_r_r32 = PyObject_GetItem(cpy_r_r23, cpy_r_r31);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 10, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r33 = CPyStatics[14]; /* 'lon' */
    cpy_r_r34 = PyObject_GetItem(cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("main.py", "get_coordinates", 10, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_INCREF(cpy_r_r30);
    CPy_INCREF(cpy_r_r34);
    cpy_r_r35.f0 = cpy_r_r30;
    cpy_r_r35.f1 = cpy_r_r34;
    CPy_DECREF(cpy_r_r35.f0);
    CPy_DECREF(cpy_r_r35.f1);
    if (CPyFloat_Check(cpy_r_r30))
        cpy_r_r36 = cpy_r_r30;
    else {
        cpy_r_r36 = NULL;
    }
    if (cpy_r_r36 != NULL) goto __LL1;
    if (cpy_r_r30 == Py_None)
        cpy_r_r36 = cpy_r_r30;
    else {
        cpy_r_r36 = NULL;
    }
    if (cpy_r_r36 != NULL) goto __LL1;
    CPy_TypeErrorTraceback("main.py", "get_coordinates", 10, CPyStatic_globals, "float or None", cpy_r_r30);
    goto CPyL23;
__LL1: ;
    if (CPyFloat_Check(cpy_r_r34))
        cpy_r_r37 = cpy_r_r34;
    else {
        cpy_r_r37 = NULL;
    }
    if (cpy_r_r37 != NULL) goto __LL2;
    if (cpy_r_r34 == Py_None)
        cpy_r_r37 = cpy_r_r34;
    else {
        cpy_r_r37 = NULL;
    }
    if (cpy_r_r37 != NULL) goto __LL2;
    CPy_TypeErrorTraceback("main.py", "get_coordinates", 10, CPyStatic_globals, "float or None", cpy_r_r34);
    goto CPyL24;
__LL2: ;
    cpy_r_r38.f0 = cpy_r_r36;
    cpy_r_r38.f1 = cpy_r_r37;
    return cpy_r_r38;
CPyL15: ;
    cpy_r_r39.f0 = 1;
    cpy_r_r39.f1 = 1;
    cpy_r_r40 = Py_None;
    cpy_r_r41 = Py_None;
    CPy_INCREF(cpy_r_r40);
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42.f0 = cpy_r_r40;
    cpy_r_r42.f1 = cpy_r_r41;
    return cpy_r_r42;
CPyL16: ;
    tuple_T2OO __tmp3 = { NULL, NULL };
    cpy_r_r43 = __tmp3;
    return cpy_r_r43;
CPyL17: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL16;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r12);
    goto CPyL16;
CPyL19: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL16;
CPyL20: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL16;
CPyL21: ;
    CPy_DECREF(cpy_r_r23);
    goto CPyL15;
CPyL22: ;
    CPy_DecRef(cpy_r_r30);
    goto CPyL16;
CPyL23: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL16;
CPyL24: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL16;
}

PyObject *CPyPy_get_coordinates(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"city", "api_key", 0};
    static CPyArg_Parser parser = {"OO:get_coordinates", kwlist, 0};
    PyObject *obj_city;
    PyObject *obj_api_key;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_city, &obj_api_key)) {
        return NULL;
    }
    PyObject *arg_city;
    if (likely(PyUnicode_Check(obj_city)))
        arg_city = obj_city;
    else {
        CPy_TypeError("str", obj_city); 
        goto fail;
    }
    PyObject *arg_api_key;
    if (likely(PyUnicode_Check(obj_api_key)))
        arg_api_key = obj_api_key;
    else {
        CPy_TypeError("str", obj_api_key); 
        goto fail;
    }
    tuple_T2OO retval = CPyDef_get_coordinates(arg_city, arg_api_key);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp4 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp4);
    PyObject *__tmp5 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp5);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "get_coordinates", 5, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_get_weather(double cpy_r_lat, double cpy_r_lon, PyObject *cpy_r_api_key) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    cpy_r_r0 = CPyStatics[15]; /* 'http://api.openweathermap.org/data/2.5/weather' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[13]; /* 'lat' */
    cpy_r_r2 = CPyStatics[14]; /* 'lon' */
    cpy_r_r3 = CPyStatics[9]; /* 'appid' */
    cpy_r_r4 = CPyStatics[16]; /* 'units' */
    cpy_r_r5 = CPyStatics[17]; /* 'metric' */
    cpy_r_r6 = PyFloat_FromDouble(cpy_r_lat);
    cpy_r_r7 = PyFloat_FromDouble(cpy_r_lon);
    cpy_r_r8 = CPyDict_Build(4, cpy_r_r1, cpy_r_r6, cpy_r_r2, cpy_r_r7, cpy_r_r3, cpy_r_api_key, cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main.py", "get_weather", 17, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r9 = CPyModule_requests;
    cpy_r_r10 = CPyStatics[10]; /* 'get' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("main.py", "get_weather", 23, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r12[2] = {cpy_r_r0, cpy_r_r8};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[51]; /* ('params',) */
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, cpy_r_r14);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("main.py", "get_weather", 23, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r16 = CPyStatics[12]; /* 'json' */
    PyObject *cpy_r_r17[1] = {cpy_r_r15};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_VectorcallMethod(cpy_r_r16, cpy_r_r18, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "get_weather", 24, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r15);
    return cpy_r_r19;
CPyL5: ;
    cpy_r_r20 = NULL;
    return cpy_r_r20;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    goto CPyL5;
CPyL8: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL5;
}

PyObject *CPyPy_get_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"lat", "lon", "api_key", 0};
    static CPyArg_Parser parser = {"OOO:get_weather", kwlist, 0};
    PyObject *obj_lat;
    PyObject *obj_lon;
    PyObject *obj_api_key;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_lat, &obj_lon, &obj_api_key)) {
        return NULL;
    }
    double arg_lat;
    arg_lat = PyFloat_AsDouble(obj_lat);
    if (arg_lat == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_lat); goto fail;
    }
    double arg_lon;
    arg_lon = PyFloat_AsDouble(obj_lon);
    if (arg_lon == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_lon); goto fail;
    }
    PyObject *arg_api_key;
    if (likely(PyUnicode_Check(obj_api_key)))
        arg_api_key = obj_api_key;
    else {
        CPy_TypeError("str", obj_api_key); 
        goto fail;
    }
    PyObject *retval = CPyDef_get_weather(arg_lat, arg_lon, arg_api_key);
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "get_weather", 15, CPyStatic_globals);
    return NULL;
}

tuple_T3OOO CPyDef_determine_emojis(PyObject *cpy_r_weather_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    double cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    double cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_feels_like_emoji;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_humidity_emoji;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_temp_emoji;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    tuple_T3OOO cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    cpy_r_r0 = CPyStatics[18]; /* 'feels_like' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_weather_data, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 29, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r2 = PyFloat_AsDouble(cpy_r_r1);
    if (cpy_r_r2 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r1); cpy_r_r2 = -113.0;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 == -113.0;
    if (unlikely(cpy_r_r3)) goto CPyL3;
CPyL2: ;
    cpy_r_r4 = CPyStatics[19]; /* 'humidity' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_weather_data, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 30, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL4;
CPyL3: ;
    cpy_r_r6 = PyErr_Occurred();
    if (unlikely(cpy_r_r6 != NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 29, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL2;
CPyL4: ;
    cpy_r_r7 = PyFloat_AsDouble(cpy_r_r5);
    if (cpy_r_r7 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r5); cpy_r_r7 = -113.0;
    }
    CPy_DECREF(cpy_r_r5);
    cpy_r_r8 = cpy_r_r7 == -113.0;
    if (unlikely(cpy_r_r8)) goto CPyL6;
CPyL5: ;
    cpy_r_r9 = CPyStatics[20]; /* 'temp' */
    cpy_r_r10 = CPyDict_GetItem(cpy_r_weather_data, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 31, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL7;
CPyL6: ;
    cpy_r_r11 = PyErr_Occurred();
    if (unlikely(cpy_r_r11 != NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 30, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL5;
CPyL7: ;
    cpy_r_r12 = PyFloat_AsDouble(cpy_r_r10);
    if (cpy_r_r12 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r10); cpy_r_r12 = -113.0;
    }
    CPy_DECREF(cpy_r_r10);
    cpy_r_r13 = cpy_r_r12 == -113.0;
    if (unlikely(cpy_r_r13)) goto CPyL9;
CPyL8: ;
    cpy_r_r14 = cpy_r_r2 >= 30.0;
    if (cpy_r_r14) {
        goto CPyL10;
    } else
        goto CPyL11;
CPyL9: ;
    cpy_r_r15 = PyErr_Occurred();
    if (unlikely(cpy_r_r15 != NULL)) {
        CPy_AddTraceback("main.py", "determine_emojis", 31, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL8;
CPyL10: ;
    cpy_r_r16 = CPyStatics[21]; /* '☀️' */
    CPy_INCREF(cpy_r_r16);
    cpy_r_feels_like_emoji = cpy_r_r16;
    goto CPyL14;
CPyL11: ;
    cpy_r_r17 = cpy_r_r2 >= 20.0;
    if (!cpy_r_r17) goto CPyL13;
    cpy_r_r18 = CPyStatics[22]; /* '☁️' */
    CPy_INCREF(cpy_r_r18);
    cpy_r_feels_like_emoji = cpy_r_r18;
    goto CPyL14;
CPyL13: ;
    cpy_r_r19 = CPyStatics[23]; /* '❄️' */
    CPy_INCREF(cpy_r_r19);
    cpy_r_feels_like_emoji = cpy_r_r19;
CPyL14: ;
    cpy_r_r20 = cpy_r_r7 >= 70.0;
    if (!cpy_r_r20) goto CPyL16;
    cpy_r_r21 = CPyStatics[24]; /* '💦' */
    CPy_INCREF(cpy_r_r21);
    cpy_r_r22 = cpy_r_r21;
    goto CPyL17;
CPyL16: ;
    cpy_r_r23 = CPyStatics[25]; /* '💧' */
    CPy_INCREF(cpy_r_r23);
    cpy_r_r22 = cpy_r_r23;
CPyL17: ;
    cpy_r_humidity_emoji = cpy_r_r22;
    cpy_r_r24 = cpy_r_r12 >= 30.0;
    if (!cpy_r_r24) goto CPyL19;
    cpy_r_r25 = CPyStatics[26]; /* '🔥' */
    CPy_INCREF(cpy_r_r25);
    cpy_r_temp_emoji = cpy_r_r25;
    goto CPyL24;
CPyL19: ;
    cpy_r_r26 = cpy_r_r12 >= 20.0;
    if (!cpy_r_r26) goto CPyL21;
    cpy_r_r27 = CPyStatics[21]; /* '☀️' */
    CPy_INCREF(cpy_r_r27);
    cpy_r_temp_emoji = cpy_r_r27;
    goto CPyL24;
CPyL21: ;
    cpy_r_r28 = cpy_r_r12 >= 10.0;
    if (!cpy_r_r28) goto CPyL23;
    cpy_r_r29 = CPyStatics[27]; /* '🌡️' */
    CPy_INCREF(cpy_r_r29);
    cpy_r_temp_emoji = cpy_r_r29;
    goto CPyL24;
CPyL23: ;
    cpy_r_r30 = CPyStatics[23]; /* '❄️' */
    CPy_INCREF(cpy_r_r30);
    cpy_r_temp_emoji = cpy_r_r30;
CPyL24: ;
    cpy_r_r31.f0 = cpy_r_feels_like_emoji;
    cpy_r_r31.f1 = cpy_r_humidity_emoji;
    cpy_r_r31.f2 = cpy_r_temp_emoji;
    return cpy_r_r31;
CPyL25: ;
    tuple_T3OOO __tmp6 = { NULL, NULL, NULL };
    cpy_r_r32 = __tmp6;
    return cpy_r_r32;
}

PyObject *CPyPy_determine_emojis(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"weather_data", 0};
    static CPyArg_Parser parser = {"O:determine_emojis", kwlist, 0};
    PyObject *obj_weather_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_weather_data)) {
        return NULL;
    }
    PyObject *arg_weather_data;
    if (likely(PyDict_Check(obj_weather_data)))
        arg_weather_data = obj_weather_data;
    else {
        CPy_TypeError("dict", obj_weather_data); 
        goto fail;
    }
    tuple_T3OOO retval = CPyDef_determine_emojis(arg_weather_data);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(3);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp7);
    PyObject *__tmp8 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp8);
    PyObject *__tmp9 = retval.f2;
    PyTuple_SET_ITEM(retbox, 2, __tmp9);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "determine_emojis", 28, CPyStatic_globals);
    return NULL;
}

char CPyDef_main(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    tuple_T2OO cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    double cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    double cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    double cpy_r_r26;
    char cpy_r_r27;
    double cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    cpy_r_r0 = CPyStatics[28]; /* '6686d8ea951a043615db0329e612361a' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[29]; /* 'Enter city name: ' */
    cpy_r_r2 = CPyModule_builtins;
    cpy_r_r3 = CPyStatics[30]; /* 'input' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "main", 59, CPyStatic_globals);
        goto CPyL21;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_r1};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "main", 59, CPyStatic_globals);
        goto CPyL21;
    }
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("main.py", "main", 59, CPyStatic_globals, "str", cpy_r_r7);
        goto CPyL21;
    }
    cpy_r_r9 = CPyDef_get_coordinates(cpy_r_r8, cpy_r_r0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9.f0 == NULL)) {
        CPy_AddTraceback("main.py", "main", 60, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r10 = cpy_r_r9.f0;
    cpy_r_r11 = cpy_r_r10;
    cpy_r_r12 = cpy_r_r9.f1;
    cpy_r_r13 = cpy_r_r12;
    cpy_r_r14 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r15 = cpy_r_r11 != cpy_r_r14;
    if (!cpy_r_r15) goto CPyL22;
    cpy_r_r16 = PyFloat_AsDouble(cpy_r_r11);
    if (cpy_r_r16 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r11); cpy_r_r16 = -113.0;
    }
    cpy_r_r17 = cpy_r_r16 == -113.0;
    if (unlikely(cpy_r_r17)) goto CPyL7;
CPyL6: ;
    cpy_r_r18 = cpy_r_r16 != 0.0;
    if (cpy_r_r18) {
        goto CPyL8;
    } else
        goto CPyL22;
CPyL7: ;
    cpy_r_r19 = PyErr_Occurred();
    if (unlikely(cpy_r_r19 != NULL)) {
        CPy_AddTraceback("main.py", "main", 60, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL6;
CPyL8: ;
    cpy_r_r20 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r21 = cpy_r_r13 != cpy_r_r20;
    if (!cpy_r_r21) goto CPyL22;
    cpy_r_r22 = PyFloat_AsDouble(cpy_r_r13);
    if (cpy_r_r22 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r13); cpy_r_r22 = -113.0;
    }
    cpy_r_r23 = cpy_r_r22 == -113.0;
    if (unlikely(cpy_r_r23)) goto CPyL11;
CPyL10: ;
    cpy_r_r24 = cpy_r_r22 != 0.0;
    if (cpy_r_r24) {
        goto CPyL12;
    } else
        goto CPyL22;
CPyL11: ;
    cpy_r_r25 = PyErr_Occurred();
    if (unlikely(cpy_r_r25 != NULL)) {
        CPy_AddTraceback("main.py", "main", 60, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL10;
CPyL12: ;
    cpy_r_r26 = PyFloat_AsDouble(cpy_r_r11);
    if (cpy_r_r26 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r11); cpy_r_r26 = -113.0;
    }
    CPy_DECREF(cpy_r_r11);
    cpy_r_r27 = cpy_r_r26 == -113.0;
    if (unlikely(cpy_r_r27)) goto CPyL14;
CPyL13: ;
    cpy_r_r28 = PyFloat_AsDouble(cpy_r_r13);
    if (cpy_r_r28 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r13); cpy_r_r28 = -113.0;
    }
    CPy_DECREF(cpy_r_r13);
    cpy_r_r29 = cpy_r_r28 == -113.0;
    if (unlikely(cpy_r_r29)) {
        goto CPyL16;
    } else
        goto CPyL15;
CPyL14: ;
    cpy_r_r30 = PyErr_Occurred();
    if (unlikely(cpy_r_r30 != NULL)) {
        CPy_AddTraceback("main.py", "main", 62, CPyStatic_globals);
        goto CPyL24;
    } else
        goto CPyL13;
CPyL15: ;
    cpy_r_r31 = PyFloat_FromDouble(cpy_r_r26);
    cpy_r_r32 = PyFloat_FromDouble(cpy_r_r28);
    cpy_r_r33 = CPyDef_display_weather(cpy_r_r31, cpy_r_r32, cpy_r_r0);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r33 == 2)) {
        CPy_AddTraceback("main.py", "main", 62, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL19;
CPyL16: ;
    cpy_r_r34 = PyErr_Occurred();
    if (unlikely(cpy_r_r34 != NULL)) {
        CPy_AddTraceback("main.py", "main", 62, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL15;
CPyL17: ;
    cpy_r_r35 = CPyStatics[31]; /* 'City not found.' */
    cpy_r_r36 = CPyModule_builtins;
    cpy_r_r37 = CPyStatics[32]; /* 'print' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("main.py", "main", 64, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r39[1] = {cpy_r_r35};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("main.py", "main", 64, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL25;
CPyL19: ;
    return 1;
CPyL20: ;
    cpy_r_r42 = 2;
    return cpy_r_r42;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL20;
CPyL22: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r13);
    goto CPyL17;
CPyL23: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r13);
    goto CPyL20;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    goto CPyL20;
CPyL25: ;
    CPy_DECREF(cpy_r_r41);
    goto CPyL19;
}

PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":main", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    char retval = CPyDef_main();
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "main", 55, CPyStatic_globals);
    return NULL;
}

char CPyDef_display_weather(PyObject *cpy_r_lat, PyObject *cpy_r_lon, PyObject *cpy_r_api_key) {
    double cpy_r_r0;
    char cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    tuple_T3OOO cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    double cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject **cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    double cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    double cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    double cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject **cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    double cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject **cpy_r_r90;
    PyObject *cpy_r_r91;
    char cpy_r_r92;
    cpy_r_r0 = PyFloat_AsDouble(cpy_r_lat);
    if (cpy_r_r0 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_lat); cpy_r_r0 = -113.0;
    }
    cpy_r_r1 = cpy_r_r0 == -113.0;
    if (unlikely(cpy_r_r1)) goto CPyL2;
CPyL1: ;
    cpy_r_r2 = PyFloat_AsDouble(cpy_r_lon);
    if (cpy_r_r2 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_lon); cpy_r_r2 = -113.0;
    }
    cpy_r_r3 = cpy_r_r2 == -113.0;
    if (unlikely(cpy_r_r3)) {
        goto CPyL4;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r4 = PyErr_Occurred();
    if (unlikely(cpy_r_r4 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 68, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL1;
CPyL3: ;
    CPy_INCREF(cpy_r_api_key);
    if (likely(PyUnicode_Check(cpy_r_api_key)))
        cpy_r_r5 = cpy_r_api_key;
    else {
        CPy_TypeError("str", cpy_r_api_key); 
        cpy_r_r5 = NULL;
    }
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 68, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL5;
CPyL4: ;
    cpy_r_r6 = PyErr_Occurred();
    if (unlikely(cpy_r_r6 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 68, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r7 = CPyDef_get_weather(cpy_r_r0, cpy_r_r2, cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 68, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r8 = CPyStatics[33]; /* 'main' */
    cpy_r_r9 = PyObject_GetItem(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 68, CPyStatic_globals);
        goto CPyL41;
    }
    if (likely(PyDict_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("main.py", "display_weather", 68, CPyStatic_globals, "dict", cpy_r_r9);
        goto CPyL41;
    }
    cpy_r_r11 = CPyDef_determine_emojis(cpy_r_r10);
    if (unlikely(cpy_r_r11.f0 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 69, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r12 = cpy_r_r11.f0;
    cpy_r_r13 = cpy_r_r12;
    cpy_r_r14 = cpy_r_r11.f1;
    cpy_r_r15 = cpy_r_r14;
    cpy_r_r16 = cpy_r_r11.f2;
    cpy_r_r17 = cpy_r_r16;
    cpy_r_r18 = CPyStatics[34]; /* 'Feels like: ' */
    cpy_r_r19 = CPyStatics[18]; /* 'feels_like' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r10, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r21 = PyFloat_AsDouble(cpy_r_r20);
    if (cpy_r_r21 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r20); cpy_r_r21 = -113.0;
    }
    CPy_DECREF(cpy_r_r20);
    cpy_r_r22 = cpy_r_r21 == -113.0;
    if (unlikely(cpy_r_r22)) goto CPyL12;
CPyL11: ;
    cpy_r_r23 = PyFloat_FromDouble(cpy_r_r21);
    cpy_r_r24 = PyObject_Str(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL13;
CPyL12: ;
    cpy_r_r25 = PyErr_Occurred();
    if (unlikely(cpy_r_r25 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL11;
CPyL13: ;
    cpy_r_r26 = CPyStatics[35]; /* '° ' */
    cpy_r_r27 = CPyStr_Build(4, cpy_r_r18, cpy_r_r24, cpy_r_r26, cpy_r_r13);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r28 = CPyModule_builtins;
    cpy_r_r29 = CPyStatics[32]; /* 'print' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL45;
    }
    PyObject *cpy_r_r31[1] = {cpy_r_r27};
    cpy_r_r32 = (PyObject **)&cpy_r_r31;
    cpy_r_r33 = _PyObject_Vectorcall(cpy_r_r30, cpy_r_r32, 1, 0);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 70, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL46;
CPyL16: ;
    CPy_DECREF(cpy_r_r27);
    cpy_r_r34 = CPyStatics[36]; /* 'Humidity: ' */
    cpy_r_r35 = CPyStatics[19]; /* 'humidity' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r10, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r37 = PyFloat_AsDouble(cpy_r_r36);
    if (cpy_r_r37 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r36); cpy_r_r37 = -113.0;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r38 = cpy_r_r37 == -113.0;
    if (unlikely(cpy_r_r38)) goto CPyL19;
CPyL18: ;
    cpy_r_r39 = PyFloat_FromDouble(cpy_r_r37);
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL44;
    } else
        goto CPyL20;
CPyL19: ;
    cpy_r_r41 = PyErr_Occurred();
    if (unlikely(cpy_r_r41 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL44;
    } else
        goto CPyL18;
CPyL20: ;
    cpy_r_r42 = CPyStatics[37]; /* '% ' */
    cpy_r_r43 = CPyStr_Build(4, cpy_r_r34, cpy_r_r40, cpy_r_r42, cpy_r_r15);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r44 = CPyModule_builtins;
    cpy_r_r45 = CPyStatics[32]; /* 'print' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL48;
    }
    PyObject *cpy_r_r47[1] = {cpy_r_r43};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r48, 1, 0);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 71, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL49;
CPyL23: ;
    CPy_DECREF(cpy_r_r43);
    cpy_r_r50 = CPyStatics[38]; /* 'Temperature: ' */
    cpy_r_r51 = CPyStatics[20]; /* 'temp' */
    cpy_r_r52 = CPyDict_GetItem(cpy_r_r10, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r53 = PyFloat_AsDouble(cpy_r_r52);
    if (cpy_r_r53 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r52); cpy_r_r53 = -113.0;
    }
    CPy_DECREF(cpy_r_r52);
    cpy_r_r54 = cpy_r_r53 == -113.0;
    if (unlikely(cpy_r_r54)) goto CPyL26;
CPyL25: ;
    cpy_r_r55 = PyFloat_FromDouble(cpy_r_r53);
    cpy_r_r56 = PyObject_Str(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL47;
    } else
        goto CPyL27;
CPyL26: ;
    cpy_r_r57 = PyErr_Occurred();
    if (unlikely(cpy_r_r57 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL47;
    } else
        goto CPyL25;
CPyL27: ;
    cpy_r_r58 = CPyStatics[35]; /* '° ' */
    cpy_r_r59 = CPyStr_Build(4, cpy_r_r50, cpy_r_r56, cpy_r_r58, cpy_r_r17);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r60 = CPyModule_builtins;
    cpy_r_r61 = CPyStatics[32]; /* 'print' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r63[1] = {cpy_r_r59};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = _PyObject_Vectorcall(cpy_r_r62, cpy_r_r64, 1, 0);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 72, CPyStatic_globals);
        goto CPyL50;
    } else
        goto CPyL51;
CPyL30: ;
    CPy_DECREF(cpy_r_r59);
    cpy_r_r66 = CPyStatics[39]; /* 'Temperature min:' */
    cpy_r_r67 = CPyStatics[40]; /* 'temp_min' */
    cpy_r_r68 = CPyDict_GetItem(cpy_r_r10, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 73, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r69 = PyFloat_AsDouble(cpy_r_r68);
    if (cpy_r_r69 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r68); cpy_r_r69 = -113.0;
    }
    CPy_DECREF(cpy_r_r68);
    cpy_r_r70 = cpy_r_r69 == -113.0;
    if (unlikely(cpy_r_r70)) goto CPyL33;
CPyL32: ;
    cpy_r_r71 = CPyModule_builtins;
    cpy_r_r72 = CPyStatics[32]; /* 'print' */
    cpy_r_r73 = CPyObject_GetAttr(cpy_r_r71, cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 73, CPyStatic_globals);
        goto CPyL42;
    } else
        goto CPyL34;
CPyL33: ;
    cpy_r_r74 = PyErr_Occurred();
    if (unlikely(cpy_r_r74 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 73, CPyStatic_globals);
        goto CPyL42;
    } else
        goto CPyL32;
CPyL34: ;
    cpy_r_r75 = PyFloat_FromDouble(cpy_r_r69);
    PyObject *cpy_r_r76[2] = {cpy_r_r66, cpy_r_r75};
    cpy_r_r77 = (PyObject **)&cpy_r_r76;
    cpy_r_r78 = _PyObject_Vectorcall(cpy_r_r73, cpy_r_r77, 2, 0);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 73, CPyStatic_globals);
        goto CPyL52;
    } else
        goto CPyL53;
CPyL35: ;
    CPy_DECREF(cpy_r_r75);
    cpy_r_r79 = CPyStatics[41]; /* 'Temperature max:' */
    cpy_r_r80 = CPyStatics[42]; /* 'temp_max' */
    cpy_r_r81 = CPyDict_GetItem(cpy_r_r10, cpy_r_r80);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 74, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r82 = PyFloat_AsDouble(cpy_r_r81);
    if (cpy_r_r82 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r81); cpy_r_r82 = -113.0;
    }
    CPy_DECREF(cpy_r_r81);
    cpy_r_r83 = cpy_r_r82 == -113.0;
    if (unlikely(cpy_r_r83)) goto CPyL38;
CPyL37: ;
    cpy_r_r84 = CPyModule_builtins;
    cpy_r_r85 = CPyStatics[32]; /* 'print' */
    cpy_r_r86 = CPyObject_GetAttr(cpy_r_r84, cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 74, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL39;
CPyL38: ;
    cpy_r_r87 = PyErr_Occurred();
    if (unlikely(cpy_r_r87 != NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 74, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL37;
CPyL39: ;
    cpy_r_r88 = PyFloat_FromDouble(cpy_r_r82);
    PyObject *cpy_r_r89[2] = {cpy_r_r79, cpy_r_r88};
    cpy_r_r90 = (PyObject **)&cpy_r_r89;
    cpy_r_r91 = _PyObject_Vectorcall(cpy_r_r86, cpy_r_r90, 2, 0);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("main.py", "display_weather", 74, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL55;
CPyL40: ;
    CPy_DECREF(cpy_r_r88);
    return 1;
CPyL41: ;
    cpy_r_r92 = 2;
    return cpy_r_r92;
CPyL42: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL41;
CPyL43: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    goto CPyL41;
CPyL44: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    goto CPyL41;
CPyL45: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r27);
    goto CPyL41;
CPyL46: ;
    CPy_DECREF(cpy_r_r33);
    goto CPyL16;
CPyL47: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r17);
    goto CPyL41;
CPyL48: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r43);
    goto CPyL41;
CPyL49: ;
    CPy_DECREF(cpy_r_r49);
    goto CPyL23;
CPyL50: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r59);
    goto CPyL41;
CPyL51: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL30;
CPyL52: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r75);
    goto CPyL41;
CPyL53: ;
    CPy_DECREF(cpy_r_r78);
    goto CPyL35;
CPyL54: ;
    CPy_DecRef(cpy_r_r88);
    goto CPyL41;
CPyL55: ;
    CPy_DECREF(cpy_r_r91);
    goto CPyL40;
}

PyObject *CPyPy_display_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"lat", "lon", "api_key", 0};
    static CPyArg_Parser parser = {"OOO:display_weather", kwlist, 0};
    PyObject *obj_lat;
    PyObject *obj_lon;
    PyObject *obj_api_key;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_lat, &obj_lon, &obj_api_key)) {
        return NULL;
    }
    PyObject *arg_lat = obj_lat;
    PyObject *arg_lon = obj_lon;
    PyObject *arg_api_key = obj_api_key;
    char retval = CPyDef_display_weather(arg_lat, arg_lon, arg_api_key);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "display_weather", 67, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r9;
    void *cpy_r_r11;
    void *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[43]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", -1, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[52]; /* ('Any',) */
    cpy_r_r6 = CPyStatics[45]; /* 'typing' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 1, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_requests;
    PyObject **cpy_r_r10[1] = {cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[1] = {2};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[54]; /* (('requests', 'requests', 'requests'),) */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[47]; /* 'main.py' */
    cpy_r_r17 = CPyStatics[48]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL7;
    cpy_r_r19 = CPyDef_main();
    if (unlikely(cpy_r_r19 == 2)) {
        CPy_AddTraceback("main.py", "<module>", 77, CPyStatic_globals);
        goto CPyL7;
    }
    return 1;
CPyL7: ;
    cpy_r_r20 = 2;
    return cpy_r_r20;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_main = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_requests = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[55];
const char * const CPyLit_Str[] = {
    "\006,http://api.openweathermap.org/geo/1.0/direct\001q\005{:{}}\000\006format\005limit",
    "\006\005appid\003get\006params\004json\003lat\003lon",
    "\003.http://api.openweathermap.org/data/2.5/weather\005units\006metric",
    "\n\nfeels_like\bhumidity\004temp\006\342\230\200\357\270\217\006\342\230\201\357\270\217\006\342\235\204\357\270\217\004\360\237\222\246\004\360\237\222\247\004\360\237\224\245\a\360\237\214\241\357\270\217",
    "\003 6686d8ea951a043615db0329e612361a\021Enter city name: \005input",
    "\a\017City not found.\005print\004main\fFeels like: \003\302\260 \nHumidity: \002% ",
    "\005\rTemperature: \020Temperature min:\btemp_min\020Temperature max:\btemp_max",
    "\006\bbuiltins\003Any\006typing\brequests\amain.py\b<module>",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0021\0000",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {4, 1, 11, 1, 44, 3, 46, 46, 46, 1, 53};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_main_internal = NULL;
CPyModule *CPyModule_main;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_requests;
tuple_T2OO CPyDef_get_coordinates(PyObject *cpy_r_city, PyObject *cpy_r_api_key);
PyObject *CPyPy_get_coordinates(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_get_weather(double cpy_r_lat, double cpy_r_lon, PyObject *cpy_r_api_key);
PyObject *CPyPy_get_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T3OOO CPyDef_determine_emojis(PyObject *cpy_r_weather_data);
PyObject *CPyPy_determine_emojis(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_main(void);
PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_display_weather(PyObject *cpy_r_lat, PyObject *cpy_r_lon, PyObject *cpy_r_api_key);
PyObject *CPyPy_display_weather(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
