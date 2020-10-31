#include "functions.h"

void sort(char arr[NUMSLOV][SLOVLEN + 1], int k)
{
    char rem[SLOVLEN + 1];
    for (int i = 0; i < (k - 1); i++)
        for (int j = i + 1; j < k; j++)
            if (strcmp(arr[i], arr[j]) > 0)
                for (int letter = 0; letter < SLOVLEN + 1; letter++)
                {
                    rem[letter] = arr[i][letter];
                    arr[i][letter] = arr[j][letter];
                    arr[j][letter] = rem[letter];
                }
}
