#include "functions.h"

int process(FILE *f, int *max)
{
    int tek = 0, pred = 0, flag = 0;
    int maxub = 1, maxvoz = 1, tekub = 1, tekvoz = 1;

    setbuf(stdout, NULL);
    printf("Input integers:\n");

    if (fscanf(f, "%d\n", &pred) == 1)
    {
        while (fscanf(f, "%d", &tek) == 1)
        {
            flag = 1;
            if (tek < pred)
            {
                tekub++;
                if (tekub > maxub)
                    maxub = tekub;
                tekvoz = 1;
            }
            else if (tek > pred)
            {
                tekvoz++;
                if (tekvoz > maxvoz)
                    maxvoz = tekvoz;
                tekub = 1;
            }
            else
            {
                tekvoz = 1;
                tekub = 1;
            }
            pred = tek;
        }
        if (flag == 0)
            return ERRNO;
        if (maxub + maxvoz == 2)
        {
            *max = 0;
            return OK;
        }
        else
        {
            *max = (maxub > maxvoz ? maxub : maxvoz);
            return OK;
        }
    }
    else
        return ERREMPTY;
}
