#include <stdio.h>
int main(){
    double x[100];
    int day,max=0,min=0,i=0;
    scanf("%d",&day);
    if (day==0){ printf("0"); return 0;}
    for ( int i=0;i<day;i++){
        scanf("%lf", &x[i]);
    } 
    do{
        if(x[i]>x[i+1]) min=i+1;
        if(x[i]<x[i+1]){
            if (x[i+1]<x[i+2]) max=i+2;
            else min=i+2;
        }
        i++;
    } while(max==0);
    for(int i=max;i<day;i++){
        if(x[i]<x[i+1]) max=i+1;    
        if(x[i]>x[i+1]){ max=i; break;}
    }
    for(int i=min;i<=max;i++){
        printf("%.2lf ",x[i]);
    }
}