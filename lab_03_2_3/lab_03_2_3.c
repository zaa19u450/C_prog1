#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ZERO -3

int input_matrix(int a[N][M], int *n, int *m);
int proiz(int i, int a[N][M], int m);
void change(int i1, int i2, int a[N][M], int m);
void sort(int a[N][M], int n, int m);
void print_matrix(int a[N][M], int n, int m);
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
    sort(a, n, m);
    print_matrix(a, n, m);
        return OK;
}
void sort(int a[N][M], int n, int m)
{
    for (int i = 0; i < (n - 1); i++)
        for (int j = n - 2; j > i - 1; j--)
            if (proiz(j, a, m) > proiz(j + 1, a, m))
                change(j, j + 1, a, m);
}
int input_matrix(int a[N][M], int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input n and m: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_INPUT;
    if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
        return ERR_RANGE;
    setbuf(stdout, NULL);
    printf("Input elements:\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_INPUT;
    return OK;
}
void change(int i1, int i2, int a[N][M], int m)
{
    int rem[M];
    for (int j = 0; j < m; j++)
        rem[j] = a[i1][j];
    for (int j = 0; j < m; j++)
        a[i1][j] = a[i2][j];
    for (int j = 0; j < m; j++)
        a[i2][j] = rem[j];
}
int proiz(int i, int a[N][M], int m)
{
    int pr = 1;
    for (int j = 0; j < m; j++)
        pr *= a[i][j];
    return pr;
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