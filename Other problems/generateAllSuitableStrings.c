#include<stdio.h>
#include <math.h> 

void printTheArray(int a[], int n){
	for (int i = 0; i < n; i++) {
		if(i==n-1) printf("%d\n", a[i]);
		else printf("%d ", a[i]);
	}
}

int checkDiff(int k, int a[]){
	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			if(a[i]==a[j]) return 0;
		}
	}
}

int checkCompare(int k, int a[]){
	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			if(a[i]>a[j]) return 0;
		}
	}
}

void generateAllSuitableStrings(int n, int k, int a[], int i){
	if (i == k) {
		if(checkDiff(k, a)!=0 && checkCompare(k, a)!=0){
			printTheArray(a, k);
			return;
		}
		else return;
	}
	for(int j=i+1;j<=n;j++){
		a[i] = j;
		generateAllSuitableStrings(n, k, a, i+1);
	}
}

int main(){
	int n,k;
	scanf("%d %d", &k, &n);
	int a[k];
	generateAllSuitableStrings(n, k, a, 0);
	return 0;
}
