#include "header.h"

int main(int argc, char**argv)
{
    FILE *f;
    int rc = OK;
    float result;
    fpos_t buf;

    if (argc != 2)
    {
        setbuf(stdout, NULL);
        printf("Error: expected main.exe <file-name>\n");
        rc = ERRNONAME;
    }
    else
    {
        f = fopen(argv[1], "r+");
        if (f)
        {
            rc = count(f, &result);
            while (rc == OK)
            {
                fgetpos (f, &buf);
                fprintf(f, "%f", result);
                fflush(f);
                fsetpos(f, &buf);
                fscanf(f, "%f", &result);
                rc = count(f, &result);
            }
            if (feof(f))
                rc = OK;
            fclose(f);
        }
        else
            rc = ERROPEN;
    }
    return rc;
}

