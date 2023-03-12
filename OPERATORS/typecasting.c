// Type casting
#include<stdio.h>
int main(void) {
    float a;
    int x = 10, y = 3;

    a = x/y;
    printf("Value of a (without casting): %f\n\n", a);
    a = (float) x/y;
    printf("Value of a (with casting): %f", a);

    return 0;
}