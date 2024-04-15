/* Viết chương trình nhập mảng chứa 20 số nguyên a) Tính tổng các số lẻ trong mảng b) Tìm min*/
#include <stdio.h>
#define MAX 20
int main(){
    int a[MAX]; 
    int i,s,min;   
    for ( i = 0; i < MAX; i++ ){
        printf("a[%d]=",i);
        scanf("%d", &a[i]);}s=0; min=a[0];
    for ( i = 0; i < MAX; i++ ){
        if (a[i] < min) min = a[i];
        if (a[i]%2==1) s= s+ a[i];
    } 
    printf("\nMinimum value in the array: %d",min);
    printf("Sum of all odd numbers: %d",s);
    return 0;
}