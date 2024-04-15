#include <stdio.h>
void swap(char a[],char b,char c){
    for(int i=0;;i++){
        if (a[i]=='\0') break;
        else if (a[i]==b) a[i]=c;
    }
}
int main(){
    char a[2048]={'\0'},b,c;
    scanf("%s %c %c",&a,&b,&c);
    swap(a,b,c);
    printf("%s",a);
}