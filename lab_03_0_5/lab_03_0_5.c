#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_NO -3

int input_matrix(int a[N][M], int *n, int *m);
int is_simple(int n);
int form(int a[N][M], int n, int m, int b[N * M]);
void turn(int b[N * M], int n2);
void put_back(int a[N][M], int n, int m, int b[N * M]);
void print_matrix(int a[N][M], int n, int m);
int main(void)
{
    int a[N][M], b[N * M], n, m, n2, exit;

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
    n2 = form(a, n, m, b);
    if (n2 == 0)
        return ERR_NO;
    turn(b, n2);
    put_back(a, n, m, b);
    print_matrix(a, n, m);
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
    setbuf(stdout, NULL);
    printf("Input elements:\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_INPUT;
    return OK;
}
int is_simple(int n)
{
    if (n > 1)
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }
    else
        return 0;
}
int form(int a[N][M], int n, int m, int b[N * M])
{
    int n2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (is_simple(a[i][j]))
                b[n2++] = a[i][j];
    return n2;
}
void turn(int b[N * M], int n2)
{
    int rem;
    for (int i = 0; i < (n2 / 2); i++)
    {
        rem = b[n2 - i - 1];
        b[n2 - i - 1] = b[i];
        b[i] = rem;
    }
}
void put_back(int a[N][M], int n, int m, int b[N * M])
{
    int n2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (is_simple(a[i][j]))
                a[i][j] = b[n2++];
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