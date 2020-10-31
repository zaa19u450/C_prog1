#ifndef HEADER_F_H
#define HEADER_F_H
#include "main_header.h"

int find_in_txt(student_struct student_arr[], FILE *file_out, int n, const char *substr);
int find_in_bin(FILE *file_in, FILE *file_out, const char *substr);

#endif // HEADER_F_H