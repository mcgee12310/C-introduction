#include <stdio.h>
#include <string.h>
void docso(int digit)
{
    if(digit==0) printf("khong");
    else if(digit==1) printf("mot");
    else if(digit==2) printf("hai");
    else if(digit==3) printf("ba");
    else if(digit==4) printf("bon");
    else if(digit==5) printf("nam");
    else if(digit==6) printf("sau");
    else if(digit==7) printf("bay");
    else if(digit==8) printf("tam");
    else if(digit==9) printf("chin");
}
int main(){
    char x[5];
    fgets(x,sizeof(x),stdin);
    if(x[2]=='\0'){
        docso((int)(x[0]-'0'));
    }
    else if (x[3]=='\0'){
        if(x[0]=='1'&&x[1]!='0') {
            printf("muoi ");
            docso((int)(x[1]-'0'));
        }
        else if(x[0]=='1'&&x[1]!='0'){
            docso((int)(x[0]-'0'));
            printf(" muoi");
        }
        else if(x[0]=='1'&&x[1]=='0'){
            printf("muoi");
        }
        else{
            docso((int)(x[0]-'0'));
            printf(" muoi ");
            docso((int)(x[1]-'0'));
        }
    }
    else if (x[4]=='\0'){
        if(x[1]=='0'&&x[2]!='0'){
            docso((int)(x[0]-'0'));
            printf(" tram ");
            printf("le ");
            docso((int)(x[2]-'0'));
        }
        else if(x[1]=='1'&&x[2]!='0') {
            docso((int)(x[0]-'0'));
            printf(" tram ");
            printf("muoi ");
            docso((int)(x[2]-'0'));
        }
        else if(x[1]=='1'&&x[2]=='0') {
            docso((int)(x[0]-'0'));
            printf(" tram ");
            printf("muoi");
        }
        else if(x[1]!='0'&&x[2]=='0') {
            docso((int)(x[0]-'0'));
            printf(" tram ");
            docso((int)(x[1]-'0'));
            printf(" muoi");
        }
        else if(x[1]=='0'&&x[2]=='0') {
            docso((int)(x[0]-'0'));
            printf(" tram");
        }
        else{
            docso((int)(x[0]-'0'));
            printf(" tram ");
            docso((int)(x[1]-'0'));
            printf(" muoi ");
            docso((int)(x[2]-'0'));
        }
    }
}