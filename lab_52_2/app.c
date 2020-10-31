#include "header_main.h"
#include "functions_to_help.h"
#include "command_ab_add.h"
#include "command_fb_find.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK, n;
    FILE *file_in;

    if ((argc < 3 || argc > 4) ||
        (argc == 3 && strcmp(argv[1], "ab")) ||
        (argc == 4 && strcmp(argv[1], "fb")))
        rc = ERRPARAM;
    else
    {
        if (!strcmp(argv[1], "fb"))
        {
            file_in = fopen(argv[2], "rb");
            if ((n = can_work(file_in)) == OK)
            {
                n = find_in_bin(file_in, argv[3]);
                if (n == 0)
                    rc = ERRNOTFOUND;
                fclose(file_in);
            }
            else
                rc = n;
        }
        else if (!strcmp(argv[1], "ab"))
        {
            file_in = fopen(argv[2], "r+b");
            if ((n = can_work(file_in)) == OK)
            {
                product_struct product;
                memset(&product, 0, sizeof(product_struct));
                n = get_new_product(&product);
                if (n == OK)
                {
                    n = add_new_product(file_in, product);
                    truncate(argv[2], n * sizeof(product_struct));
                }
                else
                    rc = n;
                fclose(file_in);
            }
            else
                rc = n;
        }
    }
    return rc;
}


