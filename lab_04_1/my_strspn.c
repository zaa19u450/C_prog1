#include "my_strspn.h"

int my_strspn(const char *string1, const char *string2)
{
    int n = 0, flag;
    for (int i = 0; string1[i] != '\0'; i++)
    {
        flag = 0;
        for (int j = 0; string2[j] != '\0'; j++)
            if (string1[i] == string2[j])
            {
                n++;
                flag = 1;
                break;
            }
        if (flag == 0)
            return n;
    }
    return n;
}
