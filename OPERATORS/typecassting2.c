// Typecasting example 2

#include <stdio.h>

int main(void) {
    int num = 20000;

    num = ((long)num * 10) / 20;

    printf("\nnum = %d", num);

    return 0;
}