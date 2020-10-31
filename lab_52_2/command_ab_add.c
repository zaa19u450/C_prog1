#include "command_ab_add.h"
#include "functions_to_help.h"

int get_new_product(product_struct *product)
{
    printf("Enter product name: ");
    if (fscanf(stdin, "%s", product->name) != 1)
        return ERRVALUE;
    printf("Enter organization name: ");
    if (fscanf(stdin, "%s", product->org) != 1)
        return ERRVALUE;
    printf("Enter cost of product: ");
    if (fscanf(stdin, "%u", &(product->cost)) != 1 || (product->cost) == 0)
        return ERRVALUE;
    printf("Enter amount of product: ");
    if (fscanf(stdin, "%u", &(product->amount)) != 1 || (product->amount) == 0)
        return ERRVALUE;
    return OK;
}

int add_new_product(FILE *f, product_struct product1)
{
    size_t n;
    product_struct product2;
    int done = 0;
    memset(&product2, 0, sizeof(product_struct));
    file_size(f, &n);
    for (int i = (int) n - 1; i >= 0 && !done; i--)
    {
        get_structure_by_pos(f, i, &product2);
        if ((product1.cost < product2.cost) ||
            ((product1.cost == product2.cost) && (product1.amount < product2.amount)))
        {
            for (size_t j = i + 1; j < n; j++)
            {
                get_structure_by_pos(f, j, &product2);
                put_structure_by_pos(f, j, product1);
                product1 = product2;
            }
            put_structure_by_pos(f, n, product1);
            done = 1;
        }
    }
    if (!done)
    {
        for (size_t j = 0; j < n; j++)
        {
            get_structure_by_pos(f, j, &product2);
            put_structure_by_pos(f, j, product1);
            product1 = product2;
        }
        put_structure_by_pos(f, n, product1);
    }
    return (int) (n + 1);
}
