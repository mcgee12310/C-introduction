#include <stdio.h>
int main(){
    int sum, n, i, a, b, c, d;
    scanf("%d", &n);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    i=0;
    sum=0;
    if(a>n){
        sum=sum+a;
        i=i+1;
    }
    if(b>n){
        sum=sum+b;
        i=i+1;
    }
    if(c>n){
        sum=sum+c;
        i=i+1;
    }
    if(d>n){
        sum=sum+d;
        i=i+1;
    }
    if(i==0) printf("0 0");
    else printf("%d %d",i, sum/i);
    return 0;
}