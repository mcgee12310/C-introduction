#include <stdio.h>
#include <math.h>
int main(){
    double money,rate;
    scanf("%lf",&rate);
    for(int i=1;;i++) {
        money=100000000.0*pow(1+rate/100,i);
        if (money>=200000000.0){
            printf("%d",i);
            break;
        }
    }
}