#ifndef FUNCTIONS_TO_HELP_H
#define FUNCTIONS_TO_HELP_H
#include "header_main.h"

int file_size(FILE *f, size_t *size);
void get_structure_by_pos(FILE *f, int pos, product_struct *product);
void put_structure_by_pos(FILE *f, int pos, product_struct product);
int can_work(FILE *f);
void print_struct(FILE *f, product_struct product);

#endif // FUNCTIONS_TO_HELP_H
