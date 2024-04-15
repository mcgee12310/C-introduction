#include <stdio.h>
int main(){
    int d[1000],m[1000],y[1000],n=0;
    double s[1000],tong=0,max=0,min=1000000000000,a;
    for(int i=0;;i++){
        scanf("%d-%d-%d %lf",&y[i],&m[i],&d[i],&s[i]);
        if(y[i]==-1) break;
        else n+=1;
    }
    if(n==0) printf("0.00 0.00 0.00");
    else{
        for(int i=0;i<n;i++){
            if(y[i]==y[i+1]&&m[i]==m[i+1]&&d[i]==d[i+1]){
                tong+=s[i];
                a+=s[i];
            } 
            else{
                tong+=s[i];
                a+=s[i];
                if(a>=max) max=a;
                if(a<=min) min=a;
                a=0;
            }
        }   
        printf("%.2lf %.2lf %.2lf",tong,max,min);
    }
}
