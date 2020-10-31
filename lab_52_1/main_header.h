#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdint.h>

#define EPSILON 1e-04
#define STUDENTS 100
#define SURLEN 25
#define NAMELEN 10

#define OK 0
#define ERRPARAM 53
#define ERROPEN -1
#define ERREMPTY -2
#define ERRNOTFOUND -3
#define ERRREADING -4
#define ERRVALUE -5

typedef struct
{
    char surname[SURLEN + 1];
    char name[NAMELEN + 1];
    uint32_t marks[4];
} student_struct;

#endif // MAIN_HEADER_H
