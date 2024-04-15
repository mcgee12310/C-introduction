#include <stdio.h>
int main(){
    char x[12];
    fgets (x, sizeof(x),stdin);
    if(x[0]=='8'&&x[1]=='4'){
        if(x[7]==x[8]&&x[8]==x[9]&&x[9]==x[10]) printf("1");
        else if(x[8]-x[7]==1&&x[9]-x[8]==1&&x[10]-x[9]==1) printf("1");
        else if(x[9]-x[8]==1&&x[10]-x[9]==1) printf("1");
        else if(x[8]==x[9]&&x[9]==x[10]) printf("1");
        else  printf("0");
    } 
    else{
        if(x[6]==x[7]&&x[7]==x[8]&&x[8]==x[9]) printf("1");
        else if(x[7]-x[6]==1&&x[8]-x[7]==1&&x[9]-x[8]==1) printf("1");
        else if(x[8]-x[7]==1&&x[9]-x[8]==1) printf("1");
        else if(x[7]==x[8]&&x[8]==x[9]) printf("1");
        else  printf("0");
    }
}