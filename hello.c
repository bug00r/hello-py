#include <Python.h>

static PyObject*
say_hello(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

static PyMethodDef HelloMethods[] =
{
     {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
     {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
   PyModuleDef_HEAD_INIT,
   "hello",   /* name of module */
   "some test here", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   HelloMethods
};

PyMODINIT_FUNC
PyInit_hello(void)
{
     //(void) Py_Initialize("hello", HelloMethods);
	 return PyModule_Create(&hellomodule);
}
