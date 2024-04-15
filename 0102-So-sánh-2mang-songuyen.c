#include <stdio.h>
int sosanh(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        if(a[i]==b[i]);
        else return 0;
    }
    return 1;
}
int main(){
    int a[256],b[256],n=0,m=0;
    printf("Nhap so phan tu cu mang: ");
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    if(n<=m) n=m;
    printf("%d",sosanh(a,b,n));
}