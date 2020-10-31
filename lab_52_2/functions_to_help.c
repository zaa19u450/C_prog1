#include "header_main.h"
#include "functions_to_help.h"

void print_struct(FILE *f, product_struct product)
{
    fprintf(f, "%s\n", product.name);
    fprintf(f, "%s\n", product.org);
    fprintf(f, "%u\n", product.cost);
    fprintf(f, "%u\n", product.amount);
}

int file_size(FILE *f, size_t *size)
{
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    if ((*size <= 0) || (*size < sizeof(product_struct)))
        return ERREMPTY;
    *size = *size / sizeof(product_struct);
    return fseek(f, 0, SEEK_SET);;
}

void get_structure_by_pos(FILE *f, int pos, product_struct *product)
{
    int binary_pos = pos * sizeof(product_struct);
    fseek(f, binary_pos, SEEK_SET);
    fread(product, sizeof(product_struct), 1, f);
}

int can_work(FILE *f)
{
    product_struct product;
    size_t size;
    memset(&product, 0, sizeof(product_struct));
    int rc = OK;
    if (f)
    {
        file_size(f, &size);
        if (size <= 0)
            rc = ERREMPTY;
        else
        {
            fseek(f, 0L, SEEK_SET);
            for (size_t i = 0; i < size; i++)
                if (fread(&product, sizeof(product_struct), 1, f) != 1 || (product.cost == 0) || (product.amount == 0))
                    rc = ERRVALUE;
        }
    }
    else
        rc = ERROPEN;
    return rc;
}

void put_structure_by_pos(FILE *f, int pos, product_struct product)
{
    int binary_pos = pos * sizeof(product_struct);
    fseek(f, binary_pos, SEEK_SET);
    fwrite(&product, sizeof(product_struct), 1, f);
}
