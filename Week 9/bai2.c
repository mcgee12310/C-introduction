/* Viết hàm is_prime nhận vào một số nguyên dương và trả về 1 nếu là số nguyên tố, 0 nếu ngược lại.*/
#include <stdio.h>
#include <math.h>
int is_prime(int n){
    int i = 0;      /* Check if any of the numbers 2, ... , n-1 divide it. */
    for(i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
            }
        }
        return 1;       /* If we got here -n is necessarily prime */
}
int main(void){  
    int num = 0, i = 0;     /* Get input from user */
    printf("enter a positive integer ");
    scanf("%d", &num);
    printf("prime numbers up to %d:\n", num);
    for(i = 2; i <= num; i++){
            if(is_prime(i)){
                printf("%d ",i);
            }
        }
    return 0;
}
    
