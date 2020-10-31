#ifndef HEADER_D_H
#define HEADER_D_H
#include "main_header.h"

void delete_arr(student_struct student_arr[], int n, FILE *file_in);
int delete_bin(FILE *f);
float mean_for_students_txt(student_struct *students, int n);
float mean_for_students_bin(FILE *file);
float mean_for_student(unsigned int student_arr[]);

#endif // HEADER_D_H