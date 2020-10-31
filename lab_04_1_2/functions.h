#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define DELIMS " ;,:-.!?\n"
#define STRLEN 256
#define SLOVLEN 16
#define NUMSLOV 128
#define ERROR -1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int split(const char *const str, char arr[NUMSLOV][SLOVLEN + 1]);
int clean(char arr[NUMSLOV][SLOVLEN + 1], int k);
void delete(char arr[NUMSLOV][SLOVLEN + 1], int i, int k);
void print_words(char arr[NUMSLOV][SLOVLEN + 1], int k);
void sort(char arr[NUMSLOV][SLOVLEN + 1], int k);

#endif

