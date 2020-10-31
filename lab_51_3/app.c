/* 
The program uses int type
* The progrm can:
* fill the binary file with random integers: command "app.exe c number file"
* display the contents of a binary file with integers: command "app.exe p file"
* sort the contents of a binary file with integers by ascending: command "app.exe s file"
* sorting algorithm: by selection
*/

#include "header.h"

int main(int argc, char**argv)
{
    FILE *f;
    int rc = OK, amount = 0;

    if (argc < 3)
    {
        setbuf(stdout, NULL);
        printf("Error: need at least 3 arguments\n");
        rc = ERRARGUMENTS;
    }
    else
    {
        if (argc == 4)
        {
            f = fopen(argv[3], "wb");
            if (f)
            {
                if ((atoi(argv[2]) > 0))
                {
                    if (create_random_bin_file(f, amount = atoi(argv[2])) != 0)
                    {
                        setbuf(stdout, NULL);
                        printf("Error while filling\n");
                        rc = ERRFILL;
                    }
                }
                else
                {
                    setbuf(stdout, NULL);
                    printf("Error: need a positive integer amount of numbers\n");
                    rc = ERRRANGE;
                }
            }
            else
            {
                setbuf(stdout, NULL);
                printf("Error in opening the file %s\n", argv[3]);
                rc = ERROPEN;
            }
        }
        else if (strcmp(argv[1], "p") == 0)
        {
            f = fopen(argv[2], "rb");
            if (f)
            {
                file_size(f, &amount);
                amount /= sizeof(int);
                if (amount <= 0)
                {
                    setbuf(stdout, NULL);
                    printf("Error: empty file %s\n", argv[2]);
                    rc = ERREMPTY;
                }
                else
                {
                    rc = print_bin_file(f);
                    if (rc == ERRREADING)
                    {
                        setbuf(stdout, NULL);
                        printf("Error in reading the file %s\n", argv[2]);
                    }
                    else if (rc == ERRSIZE)
                    {
                        setbuf(stdout, NULL);
                        printf("Error in finding the size of the file %s\n", argv[2]);
                    }
                }
            }
            else
            {
                setbuf(stdout, NULL);
                printf("Error in opening the file %s\n", argv[2]);
                rc = ERROPEN;
            }
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            f = fopen(argv[2], "r+b");
            if (f)
            {
                file_size(f, &amount);
                amount /= sizeof(int);
                if (amount <= 0)
                {
                    setbuf(stdout, NULL);
                    printf("Error: empty file %s\n", argv[2]);
                    rc = ERREMPTY;
                }
                else
                {
                    rc = sort_binary_file(f, amount);
                    if (rc)
                    {
                        setbuf(stdout, NULL);
                        printf("Error while sorting %s\n", argv[2]);
                    }
                }
            }
            else
            {
                setbuf(stdout, NULL);
                printf("Error in opening the file %s\n", argv[2]);
                rc = ERROPEN;
            }
        }
        else
        {
            setbuf(stdout, NULL);
            printf("Error: unknown command %s\n", argv[1]);
            rc = ERRCOMMAND;
        }
    }
    return rc;
}