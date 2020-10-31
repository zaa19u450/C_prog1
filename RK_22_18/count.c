#include "header.h"
int count(FILE *f, float *result)
{
    float a = 0, b = 0;
    char op = 0;
    int rc = OK;

    if ((fscanf(f, "%f", &a) == 1) && (fscanf(f, "%c", &op) == 1) && (fscanf(f, "%f", &b) == 1))
    {
        if (op == '*')
            *result = a * b;
        else if (op == '+')
            *result = a + b;
        else if (op == '-')
            *result = a - b;
        else if ((op == '/') && ((fabs(b - 0.0) < EPS) || ((b - 0.0) > EPS)))
            *result = a / b;
        else
            rc = ERROPERATION;
    }
    else
        rc = ERREADING;
    printf("!%f %c %f = %f\n", a, op, b, *result);
    return rc;
}

