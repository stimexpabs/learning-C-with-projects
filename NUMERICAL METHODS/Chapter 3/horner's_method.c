/*Horner's method is an efficient way to evaluate polynomials. 
The basic idea is to evaluate the polynomial using a sequence of 
additions and multiplications, instead of evaluating each term 
separately. This can be particularly useful when dealing with 
high-degree polynomials.*/

#include <stdio.h>

// Horner's method to evaluate polynomial
double horner(double coeffs[], int n, double x) {
    double result = coeffs[0]; // Initialize result with the coefficient of the highest-degree term
    for (int i = 1; i < n; i++) {
        result = result * x + coeffs[i]; // Evaluate the polynomial using the recursive formula
    }
    return result;
}

int main() {
    double coeffs[] = {2, 3, 1}; // Coefficients of the polynomial: 2x^2 + 3x + 1
    int n = 3; // Degree of the polynomial
    double x = 4; // Value of x for which we want to evaluate the polynomial
    double result = horner(coeffs, n, x);
    printf("The value of the polynomial at x = %f is %f\n", x, result);
    return 0;
}
