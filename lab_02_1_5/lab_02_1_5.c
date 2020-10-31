#include <stdio.h>
#define N 10

int input_array(int *a);
int find_negative(int *pa, int *pl, int *negative);
int find_positive(int *pa, int *pl, int *positive);
int result(int *p_pos, int *p_neg, int k);
int main(void)
{
    int a[N], n, negative[N], n_negative, positive[N], n_positive, k, result0;
    int *pa, *pl;

    n = input_array(a);
    if (n == -1)
    {
        setbuf(stdout, NULL);
        printf("Error: incorrect amount of elements");
        return 1;
    }
    if (n == -2)
    {
        setbuf(stdout, NULL);
        printf("Error: element is not int");
        return 2;
    }
    pa = a;
    pl = pa + n;
    n_negative = find_negative(pa, pl, negative);
    if (n_negative == 0)
    {
        printf("Error: no negative elements");
        return 1;
    }
    n_positive = find_positive(pa, pl, positive);
    if (n_positive == 0)
    {
        printf("Error: no positive elements");
        return 1;
    }
    k = n_positive < n_negative ? n_positive : n_negative;
    result0 = result(positive, negative, k);
    printf("%d", result0);
    return 0;
}
int input_array(int *a)
{
    int n, rf, *pa;
    setbuf(stdout, NULL);
    printf("Input the amount of elements of array (from one to ten): ");
    rf = scanf("%d", &n);
    if (rf != 1)
        return -1;
    if ((n <= 0) || (n > 10))
        return -1;
    setbuf(stdout, NULL);
    printf("Input int elements of array: ");
    pa = a;
    for (int i = 0; i < n; i++)
    {
        rf = scanf("%d", pa);
        if (rf != 1)
            return -2;
        pa++;
    }
    return n;
}
int find_negative(int *pa, int *pl, int *negative)
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
int find_positive(int *pa, int *pl, int *positive)
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
int result(int *p_pos, int *p_neg, int k)
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