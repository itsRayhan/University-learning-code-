#include<stdio.h>
int main(){
    char mr;
    printf("enter mehedi sir ar matha:");
    scanf("%c", &mr);

    if(mr>='A' && mr<='Z'){
        printf("uppercase\n");
    }
    else if(mr>= 'a' && mr<= 'z'){

        printf("lowercase\n");
    }
    else if(mr>= '0' && mr<= '9' ){
        printf(" latter\n");
    }
    else{
        printf("win mehedi wife");
    }
    return 0;




}
