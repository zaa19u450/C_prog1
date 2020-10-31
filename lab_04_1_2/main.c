#include "functions.h"

int main(void)
{
    char str[STRLEN + 1];
    char arr[NUMSLOV][SLOVLEN + 1] = { 0 };
    char *p = fgets(str, STRLEN + 1, stdin);

    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
        return ERROR;
    else
    {
        int k = split(str, arr);
        if (k == 0)
            return ERROR;
        k = clean(arr, k);
        sort(arr, k);
        print_words(arr, k);
    }
    return 0;
}

