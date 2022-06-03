#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "print.h"

void print(const char *str, ...)
{
    Object *obj;
    va_list args;
    va_start(args, str);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == '%')
        {
            obj = va_arg(args, Object *);
            switch (obj->t)
            {
            case TYPE_INT:
                printf("%d", *(int *)_get_p(obj));
                break;
            case TYPE_US_INT:
                printf("%d", *(unsigned short int *)_get_p(obj));
                break;
            case TYPE_CHAR_P:
                printf("%s", *(char **)_get_p(obj));
                break;
            case TYPE_OTHER:
                fprintf(stderr, "type of parameter is \033[0;31munknown\033[0;37m! \n");
                exit(1);
                break;

            default:
                print("%s", "<unknown type>");
            }
        }
        else
            printf("%c", str[i]);
    }
    va_end(args);
}