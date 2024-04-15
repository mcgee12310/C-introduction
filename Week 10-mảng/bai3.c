#include <stdio.h>
void DesSort (int a[], int n) { 
    int tmp,i,j;
    for (i = 0; i < n-1 ; i++){ 
        for (j = i+1; j < n; j++) 
            if (a[i] < a [j]) {
            tmp=a[i];
            a[i]=a[j];
            a[j]= tmp;
        }
    }
} 
void OddSort (int a[], int n) { 
    int tmp,i,j;
    for (i = 0; i < n-1 ; i++){ 
        for (j = i+1; j < n; j++) 
        if (a[i]<a[j] && (a[i]%2==1) && (a[j]%2==1)){
            tmp=a[i];
            a[i]=a[j];
            a[j]= tmp;
        }    
    }
}
int main(){
    int a[100],n,i; 
    printf("Nhap so phan tu ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++ ){
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    DesSort (a,n);
    for ( i = 0; i < n; i++ ){
        printf("%d ",a[i]);
    }
    printf("\n");
    OddSort (a,n);
    for ( i = 0; i < n; i++ ){
        if (a[i]%2==1)
        printf("%d ",a[i]);
    }
}