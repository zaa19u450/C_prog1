#include <stdio.h>

int main(void)
{
    float h, t, m;
    float normal_weight, body_mass_index;
    
    setbuf(stdout, NULL);
    printf("Enter float height in centimeters.\n");
    
    scanf("%f", &h);
    
    setbuf(stdout, NULL);
    printf("\nEnter float circumference of the chest in centimeters.\n");
    
    scanf("%f", &t);
    
    setbuf(stdout, NULL);
    printf("\nEnter float mass in kg.\n");
    
    scanf("%f", &m);

    normal_weight = h * t / 240;
    body_mass_index = 10000 * m / (h * h);

    printf("\nNormal weight: %.5f", normal_weight);
    printf("\nBody mass index: %.5f", body_mass_index);
    
    return 0;
}
