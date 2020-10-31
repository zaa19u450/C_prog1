#include "header.h"

int get_number_by_pos(FILE *f, int pos, int *num)
{
    int rc = OK, size, binary_pos = pos * sizeof(int);
    rc = file_size(f, &size);
    if (rc == 0)
    {
        if ((binary_pos < 0) || (binary_pos >= size))
            return ERRRANGE;
        else
        {
            fseek(f, binary_pos, SEEK_SET);
            if (fread(num, sizeof(int), 1, f) != 1)
                rc = ERRREADING;
        }
    }
    else
        rc = ERRSIZE;
    return rc;
}
int put_number_by_pos(FILE *f, int pos, int put)
{
    int rc = OK, size, binary_pos = pos * sizeof(int);
    rc = file_size(f, &size);
    if (rc == 0)
    {
        if ((binary_pos < 0) || (binary_pos >= size))
            return ERRRANGE;
        else
        {
            fseek(f, binary_pos, SEEK_SET);
            if (fwrite(&put, sizeof(int), 1, f) != 1)
                rc = ERRREADING;
        }
    }
    else
        rc = ERRSIZE;
    return rc;
}
int sort_binary_file(FILE *f, int amount)
{
    int rc = OK;
    int num1, num2, m;

    for (int i = 0; i < amount - 1; i++)
    {
        m = i;
        for (int j = i + 1; j < amount; j++)
        {
            rc = get_number_by_pos(f, j, &num1);
            if (!rc)
            {
                rc = get_number_by_pos(f, m, &num2);
                if (!rc)
                {
                    if (num1 < num2)
                        m = j;
                }
                else
                    return rc;
            }
            else
                return rc;
        }
        if (get_number_by_pos(f, m, &num1) || get_number_by_pos(f, i, &num2)
            || put_number_by_pos(f, i, num1) || put_number_by_pos(f, m, num2))
            return rc;
    }
    return rc;
}