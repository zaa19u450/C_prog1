#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2

int input_size(int *n, int *m);
void fill(int a[N][M], int n, int m);
void print_matrix(int a[N][M], int n, int m);
int main(void)
{
    int a[N][M], n, m, exit;

    exit = input_size(&n, &m);
    if (exit == ERR_INPUT)
    {
        setbuf(stdout, NULL);
        printf("Error input");
        return exit;
    }
    if (exit == ERR_RANGE)
    {
        setbuf(stdout, NULL);
        printf("Error in size");
        return exit;
    }
    fill(a, n, m);
    print_matrix(a, n, m);
    return OK;
}
int input_size(int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input n and m: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_INPUT;
    if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
        return ERR_RANGE;
    return OK;
}
void fill(int a[N][M], int n, int m)
{
    int steps1, steps2, steps;
    if (n % 2)
        steps1 = n / 2 + 1;
    else
        steps1 = n / 2;
    if (m % 2)
        steps2 = m / 2 + 1;
    else
        steps2 = m / 2;
    if (steps1 < steps2)
        steps = steps1;
    else
        steps = steps2;
    for (int step = 0; step < steps; step++)
    {
        for (int j = step; j < m - step; j++)
        {
            a[step][j] = step + 1;
            a[n - step - 1][j] = step + 1;
        }
        for (int i = step; i < n - step; i++)
        {
            a[i][step] = step + 1;
            a[i][m - step - 1] = step + 1;
        }
    }
}
void print_matrix(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
