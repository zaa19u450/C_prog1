#include <stdio.h>
#include <math.h>

int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    float a, b, c;
    int result, rc;
    
    setbuf(stdout, NULL);
    printf("Input float x1, y1, x2, y2, x3, y3: ");
    rc = scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    if ((rc != 6) || ((x1 == x2) && (y1 == y2)) || ((x3 == x2) && (y3 == y2)) || ((x1 == x3) && (y1 == y3))\
        || ((x3 - x1) / (x2 - x1) == (y3 - y1) / (y2 - y1)))
    {
        printf("Input error");
        return 1;
    }
    a = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    b = sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
    c = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)));
    if (((a * a) == (c * c + b * b)) || ((b * b) == (c * c + a * a)) || ((c * c) == (a * a + b * b)))
        result = 1;
    else
    {
        if (((a * a) > (c * c + b * b)) || ((b * b) > (c * c + a * a))\
            || ((c * c) > (a * a + b * b)))
            result = 2;
        else
            result = 0;
    }
    printf("The answer is: %d", result);
    return 0;
}
