// goto statement with backward jump

#include <stdio.h>
int main(void) {
    int i;
    i = 1;
    LABEL: 
    printf("%d\t", i);
    i++;
    if (i <= 10) goto LABEL;
    return 0;
}