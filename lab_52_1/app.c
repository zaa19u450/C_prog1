#include "main_header.h"
#include "header_help.h"
#include "header_s.h"
#include "header_f.h"
#include "header_d.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK, n;
    FILE *file_in, *file_out;

    if ((argc < 3) || (argc == 4) || (argc > 5) ||
        (argc == 3 && strcmp(argv[1], "sb") && strcmp(argv[1], "st") &&
        strcmp(argv[1], "dt") && strcmp(argv[1], "db")) ||
        (argc == 5 && strcmp(argv[1], "fb") && strcmp(argv[1], "ft")))
        rc = ERRPARAM;
    else
    {
        if (argc == 3)
        {
            if (!strcmp(argv[1], "st"))
            {
                file_in = fopen(argv[2], "r");
                if (file_in)
                {
                    student_struct student_arr[STUDENTS];
                    memset(&student_arr, 0, sizeof(student_struct));

                    n = create_array_of_structures(file_in, student_arr);
                    if (n > 0)
                    {
                        sort_txt(student_arr, n);
                        for (int i = 0; i < n; i++)
                            put_struct(stdout, student_arr[i]);
                    }
                    else
                        rc = n;
                    fclose(file_in);
                }
                else
                    rc = ERROPEN;
            }
            else if (!strcmp(argv[1], "sb"))
            {
                file_in = fopen(argv[2], "r+b");

                rc = can_work(file_in);
                if (rc == OK)
                {
                    sort_bin(file_in);
                    print_struct_from_bin(file_in);
                    fclose(file_in);
                }
            }
            else if (!strcmp(argv[1], "dt"))
            {
                file_in = fopen(argv[2], "r");

                if (file_in)
                {
                    student_struct student_arr[STUDENTS];
                    memset(&student_arr, 0, sizeof(student_struct));

                    n = create_array_of_structures(file_in, student_arr);

                    if (n > 0)
                    {
                        student_struct new_student_arr[STUDENTS];
                        memset(&new_student_arr, 0, sizeof(student_struct));
                        fclose(file_in);
                        file_in = fopen(argv[2], "w");
                        delete_arr(student_arr, n, file_in);
                        fclose(file_in);
                    }
                    else
                        rc = n;
                }
                else
                    rc = ERROPEN;
            }
            else if (!strcmp(argv[1], "db"))
            {
                file_in = fopen(argv[2], "r+b");

                rc = can_work(file_in);
                if (rc == OK)
                {
                    n = delete_bin(file_in);
                    truncate(argv[2], n * sizeof(student_struct));
                    fclose(file_in);
                }
            }
        }
        else if (argc == 5)
        {
            if (!strcmp(argv[1], "ft"))
            {
                file_in = fopen(argv[2], "r");
                file_out = fopen(argv[3], "w");

                if (file_in && file_out)
                {
                    student_struct student_arr[STUDENTS];
                    memset(&student_arr, 0, sizeof(student_struct));

                    n = create_array_of_structures(file_in, student_arr);
                    if (n > 0)
                    {
                        n = find_in_txt(student_arr, file_out, n, argv[4]);
                        if (n == 0)
                            rc = ERRNOTFOUND;
                    }
                    else
                        rc = n;

                    fclose(file_in);
                    fclose(file_out);
                }
                else
                    rc = ERROPEN;
            }
            else if (!strcmp(argv[1], "fb"))
            {
                file_in = fopen(argv[2], "rb");
                file_out = fopen(argv[3], "wb");
                rc = can_work(file_in);
                if (rc == OK)
                {
                    n = find_in_bin(file_in, file_out, argv[4]);
                    if (n == 0)
                        rc = ERRNOTFOUND;
                    fclose(file_in);
                    fclose(file_out);
                }
            }
        }
    }
    if (rc == ERRPARAM)
        printf("ERROR in parametrs");
    if (rc == ERROPEN)
        printf("ERROR in file opening");
    if (rc == ERREMPTY)
        printf("ERROR file is empty");
    if (rc == ERRNOTFOUND)
        printf("ERROR student not found");
    if (rc == ERRREADING)
        printf("ERROR in reading the file");
    if (rc == ERRVALUE)
        printf("ERROR in valuues in file");
    return rc;
}
