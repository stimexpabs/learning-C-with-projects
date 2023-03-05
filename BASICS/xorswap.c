// swap the contents of two numbers using bitwise XOR.

#include <stdio.h>

void main(void) {
    long num1, num2;
    printf("Enter two integers: ");
    scanf("%ld %ld", &num1, &num2);
    printf("Before Swapping:\nNumber 1 - %ld,\tNumber 2 - %ld\n\n", num1, num2);
    num1 = num1 ^ num2; 
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    /*These three lines of code use bitwise XOR to swap the values of num1 and num2 without using a temporary variable.
    num1 = num1 ^ num2; performs XOR operation on num1 and num2, storing the result in num1.
    num2 = num1 ^ num2; performs XOR operation on num1 and num2, storing the result in num2. 
    num1 now contains the original value of num2.
    num1 = num1 ^ num2; performs XOR operation on num1 and num2, storing the result in num1. 
    num1 now contains the original value of num2, and num2 now contains the original value of num1.*/
    printf("After Swapping:\nNumber 1 - %ld,\tNumber 2 - %ld\n", num1, num2);
}