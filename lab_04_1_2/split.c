#include "functions.h"

int split(const char *const str, char arr[NUMSLOV][SLOVLEN + 1])
{
    int k = 0, i = 0, j = 0, flag = 1;

    while (str[i])
    {
        for (int r = 0; r < 9; r++)
            if (str[i] == DELIMS[r])
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            if (j == (SLOVLEN + 1))
                return 0;
            arr[k][j++] = str[i];
        }
        else if (j > 0)
        {
            k++;
            j = 0;
        }
        i++;
        flag = 1;
    }
    return k;
}

int clean(char arr[NUMSLOV][SLOVLEN + 1], int k)
{
    for (int i = 0; i < (k - 1); i++)
        for (int j = i + 1; j < k; j++)
            if (strcmp(arr[i], arr[j]) == 0)
            {
                delete(arr, i, k--);
                i--;
                j--;
            }
    return k;
}

void delete(char arr[NUMSLOV][SLOVLEN + 1], int i, int k)
{
    for (int j = i; j < (k - 1); j++)
        for (int letter = 0; letter < SLOVLEN + 1; letter ++)
            arr[j][letter] = arr[j + 1][letter];
}

