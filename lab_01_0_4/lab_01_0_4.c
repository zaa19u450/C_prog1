#include <stdio.h>
#include <math.h>

int main()
{
    int s, count = 0;
    setbuf(stdout, NULL);
    printf("Input sum: ");
    scanf("%d", &s);
    count = (s - 20) / 25;
    printf("The number of bottles is %d\n", count);
    return 0;
}

