// Conditional OR Ternary Operator ( ? : )
#include <stdio.h>
int main(void) {
    int a, b;

    printf("enter two numbers: ");
    scanf("\n\n%d %d", &a, &b);

    printf("Maximum value is: %d", (a>b)? a: b);
    
    return 0;
}