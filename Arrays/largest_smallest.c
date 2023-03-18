/*
    Program to find the largest and smallest elements in an array of integers
    Author: stimexpabs
    Date: 18-03-23
*/

#include <stdio.h>
int main(void) {
    int array[100], size, i, largest, smallest;

    // Input size of array
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Input elements in array
    printf("Enter elements in the array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Assume first element as largest and smallest
    largest = array[0];
    smallest = array[0];

    // Find largest and smallest in array
    for(i = 1; i < size; i++) {
        if (largest < array[i]) largest = array[i];
        if (smallest > array[i]) smallest = array[i];
    }

    // Print the largest and smallest element
    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d", smallest);

    return 0;
}