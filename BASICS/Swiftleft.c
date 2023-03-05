// Shift inputed data by two bits to the left.

#include <stdio.h>

void main(void) {
    int Input, Output;

    printf("Enter the integer you want to left-shift(2): ");
    scanf("%d", &Input);
    printf("The left-shifted data is: %d", Output = (Input<<=2));
}