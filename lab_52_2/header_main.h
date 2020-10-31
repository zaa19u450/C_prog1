#ifndef HEADER_MAIN_H
#define HEADER_MAIN_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define NAMELEN 30
#define ORGLEN 15

#define OK 0
#define ERRPARAM 53
#define ERROPEN -1
#define ERREMPTY -2
#define ERRNOTFOUND -3
#define ERRREADING -4
#define ERRVALUE -5

typedef struct
{
    char name[NAMELEN + 1];
    char org[ORGLEN + 1];
    uint32_t cost;
    uint32_t amount;
} product_struct;

#endif // HEADER_MAIN_H
