#include <stdio.h>

int main(void)
{
    int a, n, result = 1, rc;
    
    setbuf(stdout, NULL);
    printf("Enter integer \"a\" and positive integer \"n\": ");
    rc = scanf("%d%d", &a, &n);

    if ((rc == 2) && (n > 0))
    {
        if (n != 0)
        {
            for (; n > 0;n -= 1, result *= a);
        }
        printf("a^n is %d", result);
    }
    else
    {
        printf("Input error!");
        return 1;
    }

    return 0;
}