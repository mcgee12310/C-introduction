#include <stdio.h>
int main(){
    float grade;
    do{
        printf("\n Nhap diem [0;10]: ");
        scanf("%f", &grade);
        if((grade<0)||(grade>10)) printf("\n Nhap sai, nhap lai.");
    }
    while((grade<0)||(grade>10));
    printf("\n Diem cua SV la:%.2f", grade);
    return 1;
}