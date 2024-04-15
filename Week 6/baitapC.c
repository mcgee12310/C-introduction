#include <stdio.h>
int main(){
    int i, n, max, min; 
    n = 5;
    max = 10;
    min = 1;
    printf("Du doan cua may tinh la %d.\n", n);
    printf("Nhap ket qua du doan:");
    scanf("%d", &i);
    if (i !=0) 
    while (i != 0) {
        if (i==1 && n==9) printf("Du doan cua may tinh la 1o\n");
        if (i==-1 && n==2) printf("Du doan cua may tinh la 1\n");
        if (i==-1 && n != 2){
            max = n;
            n = (max + min)/2; 
            printf("Du doan cua may tinh la %d.\n", n);
        }
        if (i==1 && n != 9){
            min = n;
            n = (max + min)/2; 
            printf("Du doan cua may tinh la %d.\n", n);
        }
        printf("Nhap ket qua du doan:");
        scanf("%d", &i);
    }
    else printf("may da du doan dung, ket thuc chuong trinh\n");
    printf("may da du doan dung, ket thuc chuong trinh\n");
return 0;
}   