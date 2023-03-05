// ASCII value of given character

#include <stdio.h>

int main(void) {
    char Input;
    
    printf("Enter any character: ");
    scanf("%c", &Input);

    printf("ASCII value of the characher '%c': %d.", Input, Input);
}