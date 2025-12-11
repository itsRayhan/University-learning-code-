#include<stdio.h>
int main(){
    int a, b, c, max, min;
    printf("enter three gf namer:");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b && a>c){
        max=a;
    }
    else if (b>c){
        max=b;
    }
    else{
        max=c;
    }

    //dzfkjgbsdfkcxmdfghdlf
      if(a<b && a<c){
        min=a;
    }
    else if (b<c){
        min=b;
    }
    else{
        min=c;
    }

    printf("output: %d\n", max);
    printf("dfjkl: %d\n",min);
    return 0;






}
