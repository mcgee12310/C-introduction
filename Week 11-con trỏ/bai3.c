/*Viết chương trình yêu cầu người dùng nhập vào 3 số thực a, b ,c. Thêm 100 vào 3 số chỉ sử dụng một con trỏ*/
#include <stdio.h>
void main(void){
    int x = 25, y = 50, z = 75;
    int *ptr;
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    ptr = &x;  // Store the address of x in ptr
    *ptr += 100; // Add 100 to thevalue in x
    ptr = &y;  // Store the address of y in ptr
    *ptr += 100; // Add 100 to thevalue in yx
    ptr = &z;  // Store the address of zin ptr
    *ptr += 100; // Add 100 to thevalue in z
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
}