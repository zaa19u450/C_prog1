#include "header_s.h"
#include "header_help.h"

void sort_txt(student_struct student_arr[], int n)
{
    student_struct temp;
    memset(&temp, 0, sizeof(student_struct));
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if ((strcmp(student_arr[i].surname, student_arr[j].surname) > 0) ||
                (strcmp(student_arr[i].surname, student_arr[j].surname) == 0 &&
                strcmp(student_arr[i].name, student_arr[j].name) > 0))
            {
                temp = student_arr[i];
                student_arr[i] = student_arr[j];
                student_arr[j] = temp;
            }
        }
}
void sort_bin(FILE *f)
{
    size_t n = 0;
    student_struct student1, student2;
    memset(&student1, 0, sizeof(student_struct));
    memset(&student2, 0, sizeof(student_struct));
    file_size(f, &n);
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = i + 1; j < n; j++)
        {
            get_structure_by_pos(f, i, &student1);
            get_structure_by_pos(f, j, &student2);

            if ((strcmp(student1.surname, student2.surname) > 0) ||
                (strcmp(student1.surname, student2.surname) == 0 &&
                strcmp(student1.name, student2.name) > 0))
            {
                put_structure_by_pos(f, j, student1);
                put_structure_by_pos(f, i, student2);
            }
        }
}


