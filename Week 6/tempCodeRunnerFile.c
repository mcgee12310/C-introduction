#include <stdio.h>
int main(){
    int hh, mm, ss;
    char c;   
    scanf("%d%c%d%c%d", &hh,&c &mm, &c, &ss);
    if (0 <= hh <= 23 && 0 <= mm <= 60 && 0 <= ss <= 60 && c == ':'){
    ss = hh*60*60 + mm*60 +ss;
    printf("%d", ss);
    }
    else printf("INCORRECT");
    return 0;
}