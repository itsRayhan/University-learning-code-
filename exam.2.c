#include<stdio.h>
int main(){
    float bs, hr, total, parsentage ;
    printf("enter the basic salary:");
    scanf("%f", &bs );

    printf("salary parsentage:");
    scanf("%f", &hr );

    parsentage = (hr/100)*bs;
    total= (bs+parsentage);

    printf("parsentage= %.2f\n", parsentage);
    printf("total= %.2f\n", total);
    return 0;




}
