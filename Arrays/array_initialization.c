#include<stdio.h>
int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    printf("The array elements are: \n");
    for(i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}