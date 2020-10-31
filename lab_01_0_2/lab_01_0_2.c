#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, h, p, bok;
    
    setbuf(stdout, NULL);
    printf("Enter float bases and height of the trapezoid.\n");
    scanf("%f%f%f", &a, &b, &h);
    
    bok = sqrtf(h * h + (a - b) * (a - b) / 4);
    p = a + b + 2 * bok;
    
    printf("The perimeter of the trapezoid is equal to %.5f", p);
    
    return 0;
}
