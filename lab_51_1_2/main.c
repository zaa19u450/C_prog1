#include "finders.h"

int main(int argc, char**argv)
{
    FILE *f;
    int rc = OK, amount = 0;
    float mean;
    if (argc != 2)
    {
        printf("main.exe <file-name>\n");
        rc = ERRNAME;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            if (find_mean(f, &mean) == OK)
            {
                fclose(f);
                f = fopen(argv[1], "r");
                if (f)
                {
                    find_amount(f, &amount, mean);
                    setbuf(stdout, NULL);
                    printf("RESULT: %d", amount);
                    fclose(f);
                }
                else
                {
                    fprintf(stderr, "Could not open %s because of %s\n",
                    argv[1], strerror(errno));
                    rc = ERROPEN;
                }
            }
            else
            {
                setbuf(stdout, NULL);
                printf("Could not read the file");
                rc = ERRINPUT;
            }
        }
        else
        {
            fprintf(stderr, "Could not open %s because of %s\n",
            argv[1], strerror(errno));
            rc = ERROPEN;
        }
    }
    return rc;
}