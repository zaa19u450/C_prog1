#include <stdio.h>
#include <stdlib.h>
#define N 10

int input_array(int *n, int a[]);
int sp_sum(int n, int a[]);
int sp_mult(int n, int a[]);

int main(void)
{
    int a[N], n, rf;

    rf = input_array(&n, a);
    if (rf == 1)
    {
        setbuf(stdout, NULL);
        printf("Error: incorrect amount of elements");
        return 1;
    }
    if (rf == 2)
    {
        setbuf(stdout, NULL);
        printf("Error: element is not int");
        return 2;
    }

    int sum, mult;
    sum = sp_sum(n, a);
    if (sum == -1)
    {
        setbuf(stdout, NULL);
        printf("Error: no appropriate elements for sum");
        return 3;
    }
    mult = sp_mult(n, a);
    if (mult == 0)
    {
        setbuf(stdout, NULL);
        printf("Error: no appropriate elements for mult");
        return 4;
    }
    printf("Sum: %d\n", sum);
    printf("Mult: %d", mult);
    return 0;
}
int input_array(int *n, int a[])
{
    int rf, i;
    setbuf(stdout, NULL);
    printf("Input the amount of elements of array (from one to ten): ");
    rf = scanf("%d", n);
    if (rf != 1)
        return 1;
    if ((*n <= 0) || (*n > 10))
        return 1;
    setbuf(stdout, NULL);
    printf("Input int elements of array: ");
    for (i = 0; i < *n; i++)
    {
        rf = scanf("%d", &a[i]);
        if (rf != 1)
            return 2;
    }
    return 0;
}
int sp_sum(int n, int a[])
{
    int sum = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] % 2) && !(a[i] % 3))
        {
            flag = 1;
            sum += a[i];
        }
    }
    if (flag)
        return sum;
    else
        return -1;
}
int sp_mult(int n, int a[])
{
    int mult = 1, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(a[i] % 2) && (a[i] % 3))
        {
            flag = 1;
            mult *= a[i];
        }
    }
    if (flag)
        return mult;
    else
        return 0;
}