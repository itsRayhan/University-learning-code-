#include<stdio.h>
int main(){
    int gr;
    printf("enter the number:");
    scanf("%d", &gr);

    if((80<=gr) && (gr>=100)){
        printf("gra:A\n");
    }
    else if ((70<=gr) && (gr>=79)){
        printf("gra:B\n");
    }
    else if ((60<=gr) && (gr>=69)){
        printf("gra:c\n");
    }
    else if((0<gr) && (gr>=59)){
        printf("gra:F\n");
    }
    else{
        printf("dkjlfhgzxf.\n");
    }
    return 0;




}
