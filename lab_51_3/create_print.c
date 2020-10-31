#include "header.h"

int create_random_bin_file(FILE *f, int amount)
{
    int num, rc = OK, wrote;
    srand(time(NULL));
    for (int i = 0; (i < amount) && (!rc); i++)
    {
        num = (rand() % 100);
        wrote = fwrite(&num, sizeof(int), 1, f);
        rc = (wrote != 1);
    }
    return rc;
}

int file_size(FILE *f, int *size)
{
    int sz;
    if (fseek(f, 0L, SEEK_END))
        return 1;
    sz = ftell(f);
    if (sz < 0)
        return 1;
    *size = sz;
    return fseek(f, 0L, SEEK_SET);
}

int print_bin_file(FILE *f)
{
    int size;
    int num;
    int read;
    int rc = OK;
    rc = file_size(f, &size);
    if (rc == 0)
    {
        for (size_t i = 0; ((rc == 0) && (i < size / sizeof(int))); i++)
        {
            read = fread(&num, sizeof(int), 1, f);
            if (read == 1)
                printf("%d ", num);
            else
                rc = ERRREADING;
        }
    }
    else
        rc = ERRSIZE;
    return rc;
}
