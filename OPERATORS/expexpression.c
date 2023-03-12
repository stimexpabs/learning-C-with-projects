// Explain Expression

#include<stdio.h>
int main(void) {
    int w, x, y, z, p;

    printf("Enter 4 integers: ");
    scanf("%d %d %d %d", &w, &x, &y, &z);

    p = (w+x)/(y-z);

    printf("Value of P = %d", p);
    return 0;
}