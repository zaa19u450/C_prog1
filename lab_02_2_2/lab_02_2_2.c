#include <stdio.h>
#include <stdlib.h>
#define N 10

int input_array(int *n, int a[]);
int find_first(int x);
int does_match(int a[], int b[], int n);
void print_array(int a[], int n);
int main(void)
{
    int a[N], b[N], n, rf, j = 0;

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
    j = does_match(a, b, n);
    if (j == 0)
    {
        setbuf(stdout, NULL);
        printf("Error: no appropriate elements");
        return 3;
    }
    print_array(b, j);
    return 0;
}
int find_first(int x)
{
    x = abs(x);
    while (x > 9)
        x /= 10;
    return x;
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
int does_match(int a[], int b[], int n)
{
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        if (abs((a[i] % 10)) == find_first(a[i]) || (a[i] % 10) == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    return j;
}