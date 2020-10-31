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

void slov_obr(char *slovo, int n);
int mas_obr(char arr[NUMSLOV][SLOVLEN + 1], int k);
void form_new_str(char arr[NUMSLOV][SLOVLEN + 1], char new_str[STRLEN + 1], int k);

#endif // FUNCTIONS_H