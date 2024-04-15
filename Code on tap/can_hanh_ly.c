#include <stdio.h>
int main(){
    int n,kg,x=0,y=0;
    scanf("%d %d",&n,&kg);
    if(kg>=7*n){
        kg-=7*n;
        do{
            if (kg>5){
                kg-=10;
                x+=1;
                continue;
            } 
            if  (kg<=5){
                kg-=5;
                y+=1;
                continue;
            } 
        } while(kg>0);
        if(x+y>n) printf("5:-1 10:-1");
        else printf("5:%d 10:%d",y,x);
    }
    else printf("5:0 10:0");
}