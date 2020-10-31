#include "header_help.h"

void get_structure_by_pos(FILE *f, int pos, student_struct *student)
{
    int binary_pos = pos * sizeof(student_struct);
    fseek(f, binary_pos, SEEK_SET);
    fread(student, sizeof(student_struct), 1, f);
}

void put_structure_by_pos(FILE *f, int pos, student_struct student)
{
    int binary_pos = pos * sizeof(student_struct);
    fseek(f, binary_pos, SEEK_SET);
    fwrite(&student, sizeof(student_struct), 1, f);
}

void put_struct(FILE *f, student_struct student)
{
    fprintf(f, "%s\n", student.surname);
    fprintf(f, "%s\n", student.name);
    for (int j = 0; j < 4; j++)
        fprintf(f, "%u ", student.marks[j]);
    fprintf(f, "\n");
}

void print_struct_from_bin(FILE *f)
{
    student_struct student;
    size_t n = 0;
    fseek(f, 0L, SEEK_SET);
    memset(&student, 0, sizeof(student_struct));
    file_size(f, &n);
    for (size_t i = 0; i < n; i++)
    {
        fread(&student, sizeof(student_struct), 1, f);
        put_struct(stdout, student);
    }
}

int file_size(FILE *f, size_t *size)
{
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    if ((*size <= 0) || (*size < sizeof(student_struct)))
        return ERROPEN;
    *size = *size / sizeof(student_struct);
    return fseek(f, 0, SEEK_SET);;
}

int can_work(FILE *f)
{
    student_struct student;
    size_t size;
    memset(&student, 0, sizeof(student_struct));
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
            {
                if (fread(&student, sizeof(student_struct), 1, f) != 1)
                    rc = ERRVALUE;
            }
        }
    }
    else
        rc = ERROPEN;
    return rc;
}

int create_array_of_structures(FILE *f, student_struct student_arr[])
{
    int i = 0;
    for (; (fscanf(f, "%s", student_arr[i].surname) == 1 && fscanf(f, "%s", student_arr[i].name) == 1); i++)
        for (int j = 0; j < 4; j++)
        {
            if (fscanf(f, "%u", &(student_arr[i].marks[j])) != 1)
                return ERRVALUE;
        }
    if (i > 0)
        return i;
    else
        return ERREMPTY;
}
