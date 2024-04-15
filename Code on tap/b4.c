#include <stdio.h>
#include <string.h>
void docso(int digit)
{
    if(digit==10) printf("thap");
    else if(digit==1) printf("nhat");
    else if(digit==2) printf("nhi");
    else if(digit==3) printf("tam");
    else if(digit==4) printf("tu");
    else if(digit==5) printf("ngu");
    else if(digit==6) printf("luc");
    else if(digit==7) printf("that");
    else if(digit==8) printf("bat");
    else if(digit==9) printf("cuu");
}
int main(){
    char x[4];
    fgets(x,sizeof(x),stdin);
    if(x[3]=='\0'&&x[2]=='\n'){
        if(x[1]=='\n'){
            docso(x[0]-'0');
        }
        else if(x[2]=='\n'&&x[1]=='0'&&x[0]=='1') docso(10);
        else if(x[1]=='0'){
            docso(x[0]-'0');
            printf(" thap");
        } 
        else if(x[0]=='1'&&x[1]!='0'){
            printf("thap ");
            docso(x[1]-'0');
        } 
        else{
            docso(x[0]-'0');
            printf(" thap ");
            docso(x[1]-'0');
        }
    }
    else{
        printf("-1");
    }
}