// goto statement with forward jump

#include <stdio.h>

int main(void) {
    int a = 10;

    printf("\tHello, Pabitra\n");

    if (a == 10) goto LABEL;

    printf("This lines will be skipped.\n");
    printf("This line too..\n");

    LABEL:
    printf("goto statement\nForward jump");

    return 0;
}