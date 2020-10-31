#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 0
#define ERRARGUMENTS -1
#define ERROPEN -2
#define ERRRANGE -3
#define ERRFILL -4
#define ERRSIZE -5
#define ERRREADING -6
#define ERRCOMMAND -7
#define ERREMPTY -8

int create_random_bin_file(FILE *f, int amount);
int file_size(FILE *f, int *size);
int print_bin_file(FILE *f);
int get_number_by_pos(FILE *f, int pos, int *num);
int put_number_by_pos(FILE *f, int pos, int put);
int sort_binary_file(FILE *f, int amount);

#endif // HEADER_H
