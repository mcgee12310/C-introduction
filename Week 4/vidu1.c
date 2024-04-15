#include <stdio.h>
int main(){
    int a, b, c;
    printf("The first number: ");
    scanf("%d", &a);
    printf("The second number: ");
    scanf("%d", &b);
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);
return 0;
}