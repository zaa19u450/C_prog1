#include "finders.h"

int find_mean(FILE *f, float *mean)
{
    float num, max, min;
    if (fscanf(f, "%f", &num) == 1)
    {
        min = num;
        max = num;
        while (fscanf(f, "%f", &num) == 1)
        {
            if (num > max)
                max = num;
            else if (num < min)
                min = num;
        }
        *mean = (max + min) / 2;
        return OK;
    }
    return ERRINPUT;
}
void find_amount(FILE *f, int *amount, float mean)
{
    float num;
    double e = 1e-17;
    while (fscanf(f, "%f", &num) == 1)
    {
        if ((fabs(num - mean) > e) && ((num - mean) > 0))
            (*amount)++;
    }
}
