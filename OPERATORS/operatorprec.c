// Program to explain Operator Precedence
#include<stdio.h>
int main(void) {
    float result;

    result = 4.0+3.0*8.0/4.0;
    printf("%f\n\n", result);

    result = 1.0/2.0+3.0;
    printf("%f\n\n", result);

    result = (1.0+2.0)/3.0;
    printf("%f\n\n", result);

    result = (1.0+2.0/3.0)+4.0;
    printf("%f\n\n", result);

    return 0;
}