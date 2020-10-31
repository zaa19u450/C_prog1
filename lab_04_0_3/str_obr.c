#include "functions.h"

void slov_obr(char *slovo, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (slovo[i] == slovo[0])
        {
            for (int j = i; j < n; j++)
                slovo[j] = slovo[j + 1];
            i--;
            n--;
        }
    }
}

int mas_obr(char arr[NUMSLOV][SLOVLEN + 1], int k)
{
    for (int i = 0; i < (k - 1); i++)
    {
        if (!strcmp(arr[i], arr[k - 1]))
        {
            for (int j = i; j < (k - 1); j++)
                strcpy(arr[j], arr[j + 1]);
            i--;
            k--;
        }
        else
            slov_obr(arr[i], strlen(arr[i]));
    }
    return k - 1;
}

void form_new_str(char arr[NUMSLOV][SLOVLEN + 1], char new_str[STRLEN + 1], int k)
{
    strcpy(new_str, arr[k - 1]);
    new_str[strlen(new_str)] = ' ';
    for (int i = (k - 2); i > 0; i--)
    {
        strcat(new_str, arr[i]);
        new_str[strlen(new_str)] = ' ';
    }
    if (k != 1)
        strcat(new_str, arr[0]);
}
