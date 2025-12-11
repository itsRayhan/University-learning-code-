#include<stdio.h>
int main(){
    float area, radius, cir;
    float pi = 3.1416;

    printf("enter radius: ");
    scanf("%f", &radius);

    cir = 2 * pi * radius;
    area = pi * radius * radius;
    printf("cir= %.2f\n", cir);
    printf("area= %.2f\n", area);
    return 0;


}

