#include <stdlib.h>
#include "object.h"

Object *_c_obj(TYPE t, void *ptr)
{
    double* f = NULL;
    Object *o = malloc(sizeof(Object));
    o->t = t;
    o->p = ptr;
    return o;
}