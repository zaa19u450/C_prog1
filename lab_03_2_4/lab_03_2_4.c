#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_SQR -3
#define ERR_NO -4

int input_matrix(int a[N][M], int *n, int *m);
int find(int a[N][M], int n);
int main(void)
{
    int a[N][M], n, m, exit;

    exit = input_matrix(a, &n, &m);
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
    if (exit == ERR_SQR)
    {
        setbuf(stdout, NULL);
        printf("Error: matrix is not square");
        return exit;
    }
    exit = find(a, n);
    if (exit == 0)
        return ERR_NO;
    else
        printf("%d", exit);
    return OK;
}
int input_matrix(int a[N][M], int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input n and m: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_INPUT;
    if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
        return ERR_RANGE;
    if (*n != *m)
        return ERR_SQR;
    setbuf(stdout, NULL);
    printf("Input elements:\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_INPUT;
    return OK;
}
int find(int a[N][M], int n)
{
    int x = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = (n - 1); j > (n - i - 1); j--)
            if ((a[i][j] % 10 == 5) || (a[i][j] % 10 == -5))
            {
                if (x == 0)
                    x = a[i][j];
                else if (a[i][j] > x)
                    x = a[i][j];
            }
    }
    return x;
}