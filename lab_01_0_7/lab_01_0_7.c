#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    float eps, tek, fx, sx, absolute, relative;
    int rc, i;
    setbuf(stdout, NULL);
    printf("Input float x and float positive eps: ");
    rc = scanf("%f%f", &x, &eps);

    if ((rc != 2) || (eps <= 0) || (eps >= 1))
    {
        printf("Input error!");
        return 1;
    }
    tek = 1;
    i = 1;
    sx = 0;
    while (fabs(tek) > eps)
    {
        sx += tek;
        tek = tek * x / i++;
    }
    fx = expl(x);
    absolute = fabs(fx - sx);
    relative = fabs(absolute / fx);

    printf("Approximate value s(x): %.6f\n", sx);
    printf("Exact value f(x): %.6f\n", fx);
    printf("Absolute error: %.6f\n", absolute);
    printf("Relative error: %.6f\n", relative);

    return 0;
}