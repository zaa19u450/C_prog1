#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#define N_mas 1000
#define N_povt 1000

void random_array(int *a);
int find_negative0(int *pa, int *pl, int *negative);
int find_negative1(int *a, int n, int *negative);
int find_negative2(int *a, int n, int *negative);
int find_positive0(int *pa, int *pl, int *positive);
int find_positive1(int *a, int n, int *positive);
int find_positive2(int *a, int n, int *positive);
int result0(int *p_pos, int *p_neg, int k);
int result1(int *positive, int *negative, int k);
int result2(int *positive, int *negative, int k);
int process0(int *pa, int *pl);
int process1(int *a);
int process2(int *a);
int64_t find_common_time0(int *a);
int64_t find_common_time1(int *a);
int64_t find_common_time2(int *a);

int main(void)
{
    int64_t time0, time1, time2;
    int a[N_mas];

    random_array(a);
    time0 = find_common_time0(a);
    printf("Time for process zero (working with pointers): %I64u \n", time0);
    time1 = find_common_time1(a);
    printf("Time for process one (using a[i]): %I64u \n", time1);
    time2 = find_common_time2(a);
    printf("Time for process two (using *(a + i)): %I64u \n", time2);
}

int64_t find_common_time0(int *a)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, common_time, sum;
    sum = 0;
    for (int i = 0; i < N_povt; i++)
    {
        gettimeofday(&tv_start, NULL);
        process0(a, (a + N_mas));
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +\
        (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
    }
    common_time = (int) sum / N_povt;
    return common_time;
}
int64_t find_common_time1(int *a)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, common_time, sum;
    sum = 0;
    for (int i = 0; i < N_povt; i++)
    {
        gettimeofday(&tv_start, NULL);
        process1(a);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +\
        (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
    }
    common_time = sum / N_povt;
    return common_time;
}
int64_t find_common_time2(int *a)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, common_time, sum;
    sum = 0;
    for (int i = 0; i < N_povt; i++)
    {
        gettimeofday(&tv_start, NULL);
        process2(a);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +\
        (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
    }
    common_time = sum / N_povt;
    return common_time;
}
void random_array(int *a)
{
    for (int i = 0; i < N_mas; i++)
        a[i] = -10 + rand() % 21;
}
int process0(int *pa, int *pl)
{
    int negative[N_mas], n_negative, positive[N_mas], n_positive, k, result;

    n_negative = find_negative0(pa, pl, negative);
    if (n_negative == 0)
        return 1;
    n_positive = find_positive0(pa, pl, positive);
    if (n_positive == 0)
        return 1;
    k = n_positive < n_negative ? n_positive : n_negative;
    result = result0(positive, negative, k);
    return result;
}

int process1(int *a)
{
    int negative[N_mas], n_negative, positive[N_mas], n_positive, k, result;

    n_negative = find_negative1(a, N_mas, negative);
    if (n_negative == 0)
        return 1;
    n_positive = find_positive1(a, N_mas, positive);
    if (n_positive == 0)
        return 1;
    k = n_positive < n_negative ? n_positive : n_negative;
    result = result1(positive, negative, k);
    return result;
}
int process2(int *a)
{
    int negative[N_mas], n_negative, positive[N_mas], n_positive, k, result;

    n_negative = find_negative2(a, N_mas, negative);
    if (n_negative == 0)
        return 1;
    n_positive = find_positive2(a, N_mas, positive);
    if (n_positive == 0)
        return 1;
    k = n_positive < n_negative ? n_positive : n_negative;
    result = result2(positive, negative, k);
    return result;
}
int find_negative0(int *pa, int *pl, int *negative)
{
    int *ptek = negative, count = 0;
    for (; pa < pl; pa++)
    {
        if (*pa < 0)
        {
            *ptek = *pa;
            ptek++;
            count++;
        }
    }
    return count;
}
int find_negative1(int *a, int n, int *negative)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            negative[count] = a[i];
            count++;
        }
    }
    return count;
}
int find_negative2(int *a, int n, int *negative)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) < 0)
        {
            *(negative + count) = *(a + i);
            count++;
        }
    }
    return count;
}
int find_positive0(int *pa, int *pl, int *positive)
{
    int *ptek = positive, count = 0;
    pl--;
    pa--;
    for (; pl > pa; pl--)
    {
        if (*pl > 0)
        {
            *ptek = *pl;
            ptek++;
            count++;
        }
    }
    return count;
}
int find_positive1(int *a, int n, int *positive)
{
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            positive[count] = a[i];
            count++;
        }
    }
    return count;
}
int find_positive2(int *a, int n, int *positive)
{
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (*(a + i) > 0)
        {
            *(positive + count) = *(a + i);
            count++;
        }
    }
    return count;
}
int result0(int *p_pos, int *p_neg, int k)
{
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        result += *p_pos * *p_neg;
        p_pos++;
        p_neg++;
    }
    return result;
}
int result1(int *positive, int *negative, int k)
{
    int result = 0;
    for (int i = 0; i < k; i++)
        result += positive[i] * negative[i];
    return result;
}
int result2(int *positive, int *negative, int k)
{
    int result = 0;
    for (int i = 0; i < k; i++)
        result += *(positive + i) * *(negative + i);
    return result;
}
