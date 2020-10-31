#include <stdio.h>
#include <stdlib.h>
#define N 10

int input_array(int *n, int a[]);
void sort(int a[], int n);
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
    sort(a, n);
    print_array(a, n);
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
void sort(int a[], int n)
{
    int x;
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                x = a[j];
                a[j] = a[i];
                a[i] = x;
            }
        }
    }
}
