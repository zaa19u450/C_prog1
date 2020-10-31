#include <stdio.h>
#define N 10

double find_mean(int a[], int n);

int main(void)
{
    int a[N];
    int n, i, rf;
    double result;

    setbuf(stdout, NULL);
    printf("Input the amount of elements of array (from one to ten): ");
    rf = scanf("%d", &n);
    if (rf != 1)
    {
        setbuf(stdout, NULL);
        printf("Error: incorrect amount of elements");
        return 1;
    }
    if ((n <= 0) || (n > 10))
    {
        setbuf(stdout, NULL);
        printf("Error: incorrect amount of elements");
        return 1;
    }
    setbuf(stdout, NULL);
    printf("Input int elements of array: ");
    for (i = 0; i < n; i++)
    {
        rf = scanf("%d", &a[i]);
        if (rf != 1)
        {
            setbuf(stdout, NULL);
            printf("Error: element is not int");
            return 1;
        }
    }
    result = find_mean(a, n);
    if (result > 0.0)
    {
        setbuf(stdout, NULL);
        printf("Error: array has no negative elements!");
        return 1;
    }
    setbuf(stdout, NULL);
    printf("Arithmetic mean of negative elements in the array: %f", result);
    return 0;
}

double find_mean(int a[], int n)
{
    int count = 0, sum = 0, i;

    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            count++;
            sum += a[i];
        }
    }
    if (count == 0)
        return 10.0;
    return (double) sum / count;
}
