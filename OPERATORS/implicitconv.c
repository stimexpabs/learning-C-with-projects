// Automatic or Implicit Type Conversion
#include<stdio.h>
int main(void) {
    int a = 10, b = 20;
    float c = 10.50;
    long d = 20L, e;

    e = ((a+c)*d)+b;

    printf("Value of e = %ld", e);

    return 0;
}