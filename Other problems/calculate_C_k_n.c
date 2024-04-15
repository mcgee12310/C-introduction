#include<stdio.h>

typedef long long ll;

ll C(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return C(k - 1, n - 1) + C(k, n - 1);
}

int main(){
	int n, k;
	scanf("%d %d", &k, &n);
	printf("%d", C(k, n)% (int)(1e9+7));
	return 0;
}