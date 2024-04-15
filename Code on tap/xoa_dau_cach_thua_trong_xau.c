#include <stdio.h>
int main(){
    char x[10000];
    int n=0;
    fgets(x,sizeof(x),stdin);
    if(x[1]=='\0') printf("EMPTY");
    else{
        while(x[n]==' '){
            n++;
        } 
        if(x[n]>='a'&&x[n]<='z'){
            printf("%c",x[n]+'A'-'a');
        }
        else printf("%c",x[n]);
        for(int i=n+1;;i++){
            if(x[i]=='\0') break;
            if(x[i]==' '&&x[i+1]==' '){
            }
            else if(x[i]==' '&&x[i+1]=='\0'){
                printf("%c",x[i]);
                break;
            }
            else printf("%c",x[i]);
        }
    }
}