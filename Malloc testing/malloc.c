#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat(const char *a,const char *b){
    char *p = (char *)malloc((strlen(a)+strlen(b)+1)*sizeof(char));
    int i,j;
    for(int i=0;a[i]!='\0';i++){
        p[i]=a[i];
    }
    for(int j=0;b[j]!='\0';j++){
        p[i+j]=b[j];
    }
    p[i+j]='\0';
    return p;
}
int main(){
    char s1[]="haha";
    char s2[]="hihi";
    char *p=my_strcat(s1,s2);
    printf("%s",p);
    free(p);
    return 0;
}