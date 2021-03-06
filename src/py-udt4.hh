/**
        @author         Christopher J. Hanks    <develop@cjhanks.name>
        @license        py-udt4:        GPLv3 
                        libudt4:        BSD 
        */


#ifndef __PY_UDT_H_
#define __PY_UDT_H_

#include <Python.h>
#include <udt/udt>

/**
        @macro RETURN_UDT_RUNTIME_ERROR 
        Set a runtime exception and return null
        */
#define RETURN_UDT_RUNTIME_ERROR \
        do {\
                PyObject *__obj = PyTuple_New(2);\
                \
                PyTuple_SetItem(__obj, 0, \
                        PyLong_FromLong(UDT::getlasterror().getErrorCode())\
                        );\
                \
                PyTuple_SetItem(__obj, 1, \
                        PyBytes_FromString(\
                                UDT::getlasterror().getErrorMessage()\
                                )\
                        );\
                \
                UDT::getlasterror().clear();\
                \
                PyErr_SetObject(pyudt4_exception_obj, __obj);\
                return NULL;\
        } while (0)

#endif // __PY_UDT_H_ 
