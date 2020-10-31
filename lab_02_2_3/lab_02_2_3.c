#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int input_array(int *n, int a[]);
int is_sqrt(int x);
int new_array(int a[], int *n);
void delete(int a[], int i, int n);
void print_array(int a[], int n);
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
    new_array(a, &n);
    if (n == 0)
    {
        setbuf(stdout, NULL);
        printf("Error: no elements left");
        return 4;
    }
    print_array(a, n);
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
int is_sqrt(int x)
{
    int i = 0;
    if (x < 0)
        return 0;
    while (i * i < x)
        i++;
    if (i * i == x)
        return 1;
    else
        return 0;
}
void delete(int a[], int i, int n)
{
    int j;
    for (j = i; j < n; j++)
        a[j] = a[j + 1];
}
int new_array(int a[], int *n)
{
    int i;
    for (i = 0; i < *n; i ++)
    {
        if (is_sqrt(a[i]))
        {
            *n -= 1;
            delete(a, i, *n);
            i--;
        }
    }
    return 0;
}
void print_array(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        setbuf(stdout, NULL);
        printf("%d ", a[i]);
    }
}