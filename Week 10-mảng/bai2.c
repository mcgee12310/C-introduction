/* Cho một mảng gồm các phần tử được nhập vào bởi người dùng.Tính tổng của các cực trị địa phương trong mảng (cực trị địa phương là phần tử có giá trị lớn hơn phần tử liền trước và liền sau nó) */
#include <stdio.h>
#define MAX 20
int main(){
    int a[MAX]; 
    int i,sum;   
    for ( i = 0; i < MAX; i++ ){
        printf("a[%d]=",i);
        scanf("%d", &a[i]);
    }
    sum=0;
    for (i=1; i<=20-1; i++){
        if (a[i]>=a[i-1] && a[i]>=a[i+1]) sum +=a[i];
    }
    printf("%d",sum);
}