#include <stdio.h>
int main(){
    char x[1000];
    int d,n;
    fgets(x,sizeof(x),stdin);
    for(int i=0;;i++){
        if(x[i]=='\n'){
            n=i;
            break;
        }
    }
    if(n==1) return 0;
    for(int i=0;i<=n;i++){
        if(x[i]-x[i-1]==1){
            if(x[i-1]!='0') printf("%c",x[i-1]);
            d=1;
        } 
        else{
            if(d==1){
                if(x[i-1]!='0') printf("%c ",x[i-1]);
                d=0;
                continue;
            }
        }
    }
}