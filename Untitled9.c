#include<stdio.h>
int main(){
    int lp ;
    printf("enter year:");
    scanf("%d", &lp);

    if((lp%4==0 && lp%100!=0) || (lp%400==0)){
        printf("%d id leap year:", lp);
    }
    else{
        printf("%d is not leap year:", lp);

    }






















}
