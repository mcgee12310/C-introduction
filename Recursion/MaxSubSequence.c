#include <stdio.h>
 
int max(const int a, const int b){
    if(a>=b) return a;
    else return b;
}

int maxleft (int a[], int i, int j)
{
    int maxsum = 0;
    int sum = 0;
    for (int k = j; k >= i; k--){
        sum = sum + a[k];
        if(sum > maxsum) {
            maxsum = sum;
        }
    }
    return maxsum;
}

int maxright (int a[], int i, int j){
    int maxsum = 0;
    int sum = 0;
    for (int k = i; k <= j; k++){
        sum = sum + a[k];
        if(sum > maxsum) {
            maxsum = sum;
        }
    }
    return maxsum;
}

int maxsub(int a[], int i, int j){
    if (i == j) return a[i];
    int m = (i + j)/2;
    int wL = maxsub (a, i, m);
    int wR = maxsub (a, m+1, j);
    int wM = maxleft(a, i, m) + maxright(a, m+1, j);
    return max(max(wL, wR), wM);
}

int main ()
{
    int a[1000000]={'\0'}, n;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
     
    int sum = maxsub (a, 0, n);
    printf("%d",sum);

    return 0;
}