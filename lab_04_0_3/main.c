#include "functions.h"

int main(void)
{
    char str[STRLEN + 1];
    char *p = fgets(str, STRLEN + 1, stdin);

    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
        return ERROR;
    else
    {
        char arr[NUMSLOV][SLOVLEN + 1] = { 0 };
        int k = 0;
        p = strtok(str, DELIMS);
        while (p)
        {
            if (strlen(p) > SLOVLEN)
                return ERROR;
            strncpy(arr[k], p, sizeof(arr[k]) - 1);
            arr[k][sizeof(arr[k]) - 1] = '\0';
            k++;
            p = strtok(NULL, DELIMS);
        }
        if (k == 0)
            return ERROR;
        k = mas_obr(arr, k);
        if (k == 0)
            return ERROR;
        char new_str[STRLEN + 1] = { 0 };
        form_new_str(arr, new_str, k);
        printf("Result: %s", new_str);
    }
    return 0;
}
