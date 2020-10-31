#ifndef FINDERS_H
#define FINDERS_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#define OK 0
#define ERRNAME -1
#define ERROPEN -2
#define ERRINPUT -3

int find_mean(FILE *f, float *mean);
void find_amount(FILE *f, int *amount, float mean);


#endif