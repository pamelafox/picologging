#include <Python.h>
#include <structmember.h>
#include <cstddef>

#ifndef PICOLOGGING_FORMATTER_H
#define PICOLOGGING_FORMATTER_H

typedef struct {
    PyObject_HEAD
    PyObject *fmt;
    PyObject *dateFmt;
    PyObject *style;
} Formatter;

int Formatter_init(Formatter *self, PyObject *args, PyObject *kwds);
PyObject* Formatter_format(Formatter *self, PyObject *record);
PyObject* Formatter_dealloc(Formatter *self);

PyAPI_DATA(PyTypeObject) FormatterType;

#ifdef Py_IS_TYPE
#define Formatter_CheckExact(op) Py_IS_TYPE(op, &FormatterType)
#else
#define Formatter_CheckExact(op) (Py_TYPE(op) == &FormatterType)
#endif

#endif // PICOLOGGING_FORMATTER_H