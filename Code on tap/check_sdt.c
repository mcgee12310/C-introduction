#include <stdio.h>
int main(){
    char x[12];
    fgets (x, sizeof(x),stdin);
    if(x[0]=='8'&&x[1]=='4'){
        if(x[2]=='9'&&x[3]=='6') printf("1");
        else if (x[2]=='9'&&x[3]=='7') printf("1");
        else if (x[2]=='9'&&x[3]=='8') printf("1");
        else if (x[2]=='8'&&x[3]=='6') printf("1");
        else if (x[2]=='3'&&x[3]=='2') printf("1");
        else if (x[2]=='3'&&x[3]=='3') printf("1");
        else if (x[2]=='3'&&x[3]=='4') printf("1");
        else if (x[2]=='3'&&x[3]=='5') printf("1");
        else if (x[2]=='3'&&x[3]=='6') printf("1");
        else if (x[2]=='3'&&x[3]=='7') printf("1");
        else if (x[2]=='3'&&x[3]=='8') printf("1");
        else if (x[2]=='3'&&x[3]=='9') printf("1");
        else printf("0");
    }
    else {
        if(x[1]=='9'&&x[2]=='6') printf("1");
        else if (x[1]=='9'&&x[2]=='7') printf("1");
        else if (x[1]=='9'&&x[2]=='8') printf("1");
        else if (x[1]=='8'&&x[2]=='6') printf("1");
        else if (x[1]=='3'&&x[2]=='2') printf("1");
        else if (x[1]=='3'&&x[2]=='3') printf("1");
        else if (x[1]=='3'&&x[2]=='4') printf("1");
        else if (x[1]=='3'&&x[2]=='5') printf("1");
        else if (x[1]=='3'&&x[2]=='6') printf("1");
        else if (x[1]=='3'&&x[2]=='7') printf("1");
        else if (x[1]=='3'&&x[2]=='8') printf("1");
        else if (x[1]=='3'&&x[2]=='9') printf("1");
        else printf("0");
    }
}