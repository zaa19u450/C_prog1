#include "functions.h"

int main(void)
{
    FILE *f = stdin;
    int max = 0;
    int rc = OK;

    rc = process(f, &max);
    if (rc == OK)
    {
        setbuf(stdout, NULL);
        printf("RESULT: %d", max);
    }
    else if (rc == ERRNO)
    {
        setbuf(stdout, NULL);
        printf("No appropriate numbers\n");
    }
    else if (rc == ERREMPTY)
    {
        setbuf(stdout, NULL);
        printf("No input numbers\n");
    }
    return rc;
}
