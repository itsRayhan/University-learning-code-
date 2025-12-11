
#include <stdio.h>

int main() {
    int arr[5] = {4, 7, 1, 3, 9};
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}

