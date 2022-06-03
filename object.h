#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "typeof.h"
#include <string.h>

typedef struct
{
    TYPE t;
    void *p;
} Object;

Object *_c_obj(TYPE t, void *ptr);

#define obj(x) _c_obj(typeof((x)), (void*)(x))
#define _get_p(x) (&(x)->p)
#endif