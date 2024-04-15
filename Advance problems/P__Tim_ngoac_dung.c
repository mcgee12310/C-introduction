#include <stdio.h>

void print(int a[], int n){
	for (int i = 0; i < n; i++) {
		if(i==n-1) printf("%d ", a[i]);
		else printf("%d", a[i]);
	}
}

int check(int a[], int n){
    int dem1=0, dem2=0;
    for(int i=0; i<n; i++){
        if(a[i]==1) dem1++;
        if(a[i]==2) dem2++;
        if(dem1<dem2) return 0;
    }
    if(dem1==dem2) return 1;
    else return 0;
}

void generate(int a[], int n, int i){
    while(a[i]!=0) i++;
    if(i>=n){
        if(check(a, n)==1){
            print(a, n);
            return;
        }
        else return;
    }
    a[i]=1;
    generate(a, n, i+1);
    a[i]=2;
	generate(a, n, i+1);
    a[i]=0;
}

int main() { 
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0) cnt++;
    }
    if(cnt==0){
        if(check(a, n)==1){
            print(a, n);
            return 0;
        } 
        else return 0;
    } 
    generate(a, n, 0);
}
