#include <stdio.h>
int main(void) {
    int n, m; /* lower and upper bounds */
    int sum;  /* sum *//** Get the numbers*/
    printf("Enter first number: ");
    scanf("%d", &n);
    printf("Enter second number: ");
    scanf("%d", &m);
    sum = n+m;
    /** Print results*/
    printf("Sum of %d and %d = %d\n", n, m, sum);
    return 0;
}