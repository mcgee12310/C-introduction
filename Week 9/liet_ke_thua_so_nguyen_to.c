#include <stdio.h>
#include <math.h>
int main(){  
    int n;
    printf("enter a positive integer ");
    scanf("%d", &n);
    printf("%d=",n);
    do{
        for(int i=2;i<=n;i++){
            if(n%i==0 && n!=i){
            printf("%d*",i);
            n=n/i;
            break;
            }
            else if(n%i==0 && n==i){ printf("%d",i); n=1;}           
            }
        }
    while(n!=1);
}