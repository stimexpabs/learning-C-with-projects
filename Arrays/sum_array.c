#include <stdio.h>
int main(void) {
    int array[100], n, sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("enter the elements in the array: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    printf("sum of all elements in the array is: %d\n", sum);

    return 0;
}