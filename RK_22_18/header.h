#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXAMOUNT 10
#define EPS 1e-4

#define OK 0
#define ERRREADING -1
#define ERROPEN -2
#define ERRNONAME -3
#define ERROPERATION -4
#define ERREADING -5

int count(FILE *f, float *result);

#endif // HEADER_H
