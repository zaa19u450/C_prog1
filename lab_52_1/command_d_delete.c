#include "header_d.h"
#include "header_help.h"

float mean_for_student(unsigned int student_arr[])
{
    float sum = 0;
    for (int i = 0; i < 4; i++)
        sum += student_arr[i];
    sum /= 4;
    return sum;
}
float mean_for_students_bin(FILE *file)
{
    size_t size;
    file_size(file, &size);
    student_struct student;
    memset(&student, 0, sizeof(student_struct));
    float sum = 0;
    float mean = 0;
    for (size_t i = 0; i < size; i++)
    {
        get_structure_by_pos(file, i, &student);
        sum += mean_for_student(student.marks);
    }
    mean = sum / size;
    return mean;
}
float mean_for_students_txt(student_struct *students, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mean_for_student(students[i].marks);
    }
    sum /= n;
    return sum;
}
int delete_bin(FILE *f)
{
    student_struct student;
    size_t size;
    float total_mean = mean_for_students_bin(f);
    int written = 0;

    fseek(f, 0L, SEEK_SET);
    file_size(f, &size);
    memset(&student, 0, sizeof(student_struct));
    for (size_t i = 0; i < size; i++)
    {
        get_structure_by_pos(f, i, &student);
        if (fabs(mean_for_student(student.marks) - total_mean) < EPSILON ||
            (mean_for_student(student.marks) - total_mean) > 0)
            put_structure_by_pos(f, written++, student);
    }
    return written;
}

void delete_arr(student_struct student_arr[], int n, FILE *file_in)
{
    float total_mean = mean_for_students_txt(student_arr, n);

    for (int i = 0; i < n; i++)
        if (fabs(mean_for_student(student_arr[i].marks) - total_mean) < EPSILON ||
            (mean_for_student(student_arr[i].marks) - total_mean) > 0)
            put_struct(file_in, student_arr[i]);
}
