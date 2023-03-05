// program to read total seconds and convert it into hours, min, and sec.

#include <stdio.h>

void main(void) {
    int total_s, hh, mm, ss;

    printf("Enter total seconds(Integer-Only): ");
    scanf("%d", &total_s);

    hh = total_s / 3600;
    total_s %= 3600;
    mm = total_s / 60;
    ss = total_s % 60;
    
    printf("Hours: %d, Min: %d, Sec: %d.", hh, mm, ss);
}