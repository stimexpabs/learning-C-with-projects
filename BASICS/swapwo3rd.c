// swapping of two numbers without third variable

#include <stdio.h>

void main(void) {
    int num1, num2;
    printf("Enter two Integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Before swapping:\nNumber1 = %d\tNumber2 = %d\n\n", num1, num2);
    num1 = num1 + num2 - (num2 = num1);
    /*The expression num1 = num1 + num2 - (num2 = num1) is used to swap the values of
    num1 and num2 without using a temporary variable. Here's how it works:

    num2 = num1: This sets the value of num2 to be equal to num1. 
    Note that this assignment is evaluated first, before the rest of the expression.

    num1 + num2: This computes the sum of the original values of num1 and num2.

    num1 + num2 - (num2 = num1): The right-hand side of this expression evaluates 
    to the sum of the original values of num1 and num2, minus the new value of num2
    (which is equal to the original value of num1). The parentheses are used to ensure
    that the assignment to num2 is evaluated first, before the subtraction.
    The final result of this expression is the new value of num1, which is assigned back to the variable num1.
    This effectively swaps the values of num1 and num2. To understand the order of evaluation, 
    it's important to note that the C language specification guarantees that assignments are evaluated from right to left. 
    This means that the right-hand side of the expression (num2 = num1) is evaluated first, 
    before the subtraction operation. The new value of num2 is then used in the subtraction. 
    Finally, the new value of num1 is computed and assigned back to the variable num1.*/
    printf("After swapping:\nNumber1 = %d\tNumber2 = %d\n\n", num1, num2);
}