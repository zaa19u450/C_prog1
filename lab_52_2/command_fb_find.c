#include "command_fb_find.h"
#include "functions_to_help.h"

int find_in_bin(FILE *file_in, const char *substr)
{
    size_t size;
    product_struct product;
    memset(&product, 0, sizeof(product_struct));
    int written = 0;
    file_size(file_in, &size);

    for (size_t i = 0; i < size; i++)
    {
        get_structure_by_pos(file_in, i, &product);
        if (strncmp(&(product.name[strlen(product.name) - strlen(substr)]), substr, strlen(substr)) == 0)
        {
            print_struct(stdout, product);
            written++;
        }
    }
    return written;
}
