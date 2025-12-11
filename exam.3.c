#include<stdio.h>
int main(){
    int day, year, month, remain ;
    printf("enter your day:");
    scanf("%d", &day );

    year=(day/365);
    remain= day-year*365;

    month= remain/30;
    day= remain%30;

    printf("year: %d\n ", year);
    printf("month: %d\n ", month);
    printf("day: %d\n ", day);
    return 0;



}
