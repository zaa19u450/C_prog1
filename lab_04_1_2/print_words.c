#include "functions.h"

void print_words(char arr[NUMSLOV][SLOVLEN + 1], int k)
{
    printf("Result:");
    for (int i = 0; i < k; i++)
        printf("%s ", arr[i]);
}
