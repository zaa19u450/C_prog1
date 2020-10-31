#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ZERO -3
#define ERROR_ONE -4

int input_matrix(int a[N][M], int *n, int *m);
int check(int j, int a[N][M], int n);
void print_array(int b[M], int m);
int main(void)
{
    int a[N][M], b[M] = { 0 }, n, m, exit;

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
    if (exit == ERROR_ONE)
    {
        print_array(b, m);
        return OK;
    }
    for (int j = 0; j < m; j++)
    {
        exit = check(j, a, n);
        b[j] = exit;
    }
    print_array(b, m);
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
    if (*n == 1)
        return ERROR_ONE;
    return OK;
}
int check(int j, int a[N][M], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        if ((a[i][j] * a[i + 1][j]) >= 0)
            return 0;
    }
    return 1;
}
void print_array(int b[M], int m)
{
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);
}