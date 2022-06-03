#ifndef __TYPE_H__
#define __TYPE_H__

typedef enum
{
  TYPE_CHAR,
  TYPE_U_CHAR,
  TYPE_S_INT,
  TYPE_US_INT,
  TYPE_INT,
  TYPE_U_INT,
  TYPE_L_INT,
  TYPE_UL_INT,
  TYPE_LL_INT,
  TYPE_ULL_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_L_DOUBLE,
  TYPE_VOID_P,
  TYPE_CHAR_P,
  TYPE_INT_P,
  TYPE_OTHER
} TYPE;

#define typeof(x) _Generic((x),                                  \
                           unsigned char                         \
                           : TYPE_U_CHAR,                        \
                             char                                \
                           : TYPE_CHAR, signed char              \
                           : TYPE_CHAR,                          \
                             short int                           \
                           : TYPE_S_INT, unsigned short int      \
                           : TYPE_US_INT,                        \
                             int                                 \
                           : TYPE_INT, unsigned int              \
                           : TYPE_U_INT,                         \
                             long int                            \
                           : TYPE_L_INT, unsigned long int       \
                           : TYPE_UL_INT,                        \
                             long long int                       \
                           : TYPE_UL_INT, unsigned long long int \
                           : TYPE_ULL_INT,                       \
                             float                               \
                           : TYPE_FLOAT, double                  \
                           : TYPE_DOUBLE,                        \
                             long double                         \
                           : TYPE_L_DOUBLE, char *               \
                           : TYPE_CHAR_P,                        \
                             void *                              \
                           : TYPE_VOID_P, int *                  \
                           : TYPE_INT_P,                         \
                             default                             \
                           : TYPE_OTHER)

#endif