#include <stdio.h>
int main(){
    int n;
    do{
        printf("\n Nhap diem danh gia 1(qua) hoac 2(truot): ");
        scanf("%d", &n);
        if((n!=1)&&(n!=2)) printf("\n Nhap sai, nhap lai.");
    }
    while((n!=1)&&(n!=2));
    if (n==1) printf("\n Qua.");
    else printf("\n Truot.");
    return 0;
}