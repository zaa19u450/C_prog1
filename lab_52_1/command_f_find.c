#include "header_f.h"
#include "header_help.h"

int find_in_bin(FILE *file_in, FILE *file_out, const char *substr)
{
    size_t size;
    student_struct student;
    int written = 0;
    memset(&student, 0, sizeof(student_struct));
    file_size(file_in, &size);

    for (size_t i = 0; i < size; i++)
    {
        get_structure_by_pos(file_in, i, &student);
        if (!strncmp(student.surname, substr, strlen(substr)))
        {
            fwrite(&student, sizeof(student_struct), 1, file_out);
            written++;
        }
    }
    return written;
}

int find_in_txt(student_struct student_arr[], FILE *file_out, int n, const char *substr)
{
    int written = 0;
    for (int i = 0; i < n; i++)
    {
        if (!strncmp(student_arr[i].surname, substr, strlen(substr)))
        {
            put_struct(file_out, student_arr[i]);
            written++;
        }
    }
    return written;
}
