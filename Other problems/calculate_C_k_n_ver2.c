#include<stdio.h>
typedef long long ll;

//const int MOD=1000000007;
ll C[1001][1001];
void init(){
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=i;j++){
			C[i][j]=0;
			if(j==0 || j==i){
				C[i][j]=1;
			}
			else{
				C[i][j]=C[i-1][j-1]+C[i-1][j];
				C[i][j] %= (int)(1e9+7);
			}
		}
	}
}
int main(){
	init();
	int n,k;
    scanf("%d %d", &k, &n);
	printf("%d", C[n][k]);
	return 0;
}