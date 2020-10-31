#include <stdio.h>
#define N 20
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERROR_TWO -3

int input_matrix(int a[N][M], int *n, int *m);
int does_match(int a[N][M], int i, int m);
int sum(int x);
void add_row(int i, int a[N][M], int n, int m);
void print_matrix(int a[N][M], int n, int m);
int main(void)
{
    int a[N][M], n, m, ex;

    ex = input_matrix(a, &n, &m);
    if (ex == ERR_INPUT)
    {
        setbuf(stdout, NULL);
        printf("Error input");
        return ex;
    }
    if (ex == ERR_RANGE)
    {
        setbuf(stdout, NULL);
        printf("Error in size");
        return ex;
    }
    if (ex == ERROR_TWO)
    {
        setbuf(stdout, NULL);
        printf("Error: there are less then two columns");
        return ex;
    }
    for (int i = 0; i < n; i++)
    {
        ex = does_match(a, i, m);
        if (ex)
        {
            n++;
            add_row(i, a, n, m);
            i++;
        }
    }
    print_matrix(a, n, m);
    return 0;
}
int input_matrix(int a[N][M], int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input n and m: ");
    if (scanf("%d%d", n, m) != 2)
        return ERR_INPUT;
    if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
        return ERR_RANGE;
    if (*m < 2)
        return ERROR_TWO;
    setbuf(stdout, NULL);
    printf("Input elements:\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_INPUT;
    return OK;
}
int sum(int x)
{
    if (x == 0)
        return 0;
    else if (x < 0)
        x *= -1;
    int result = 0;
    while (x > 0)
    {
        result += x % 10;
        x /= 10;
    }
    return result;
}
int does_match(int a[N][M], int i, int m)
{
    int result = 0;
    for (int j = 0; j < m; j++)
    {
        if (sum(a[i][j]) % 2)
        {
            result++;
            if (result == 2)
                return 1;
        }
    }
    return 0;
}
void add_row(int i, int a[N][M], int n, int m)
{
    for (int ii = (n - 1); ii > i; ii--)
    {
        for (int j = 0; j < m; j++)
            a[ii][j] = a[ii - 1][j];
    }
    for (int j = 0; j < m; j++)
        a[i][j] = -1;
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
