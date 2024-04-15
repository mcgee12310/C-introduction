#include <stdio.h>

typedef struct address{
    char name[100];
    char phone[11];
    char email[100];
} address_t;

address_t input_address(){
    address_t tmp[2];
    printf("nhap thong tin ");
    for (int i=0;i<2;i++){
        scanf("%s",&tmp[i].name);
        scanf("%s",&tmp[i].phone);
        scanf("%s",&tmp[i].email);
    }
    return tmp[2];
}

int main(){
    address_t tmp[2];
    input_address();
    printf("%s",tmp[1].name);
    for (int i=0;i<2;i++){
        printf("%s %s %s\n",tmp[i].name,tmp[i].phone,tmp[i].email);
    }
}