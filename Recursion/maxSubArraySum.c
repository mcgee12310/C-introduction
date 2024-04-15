#include <stdio.h>
#include<stdlib.h>

int main() {
  int n;
  int *a = (int *)malloc(100000*sizeof(int));
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int maxSum=0;
  for(int i=0; i<n; i++){
    int sum=0;
    for(int j=i; j<n; j++){
        sum+=a[j];
        if(sum>maxSum) maxSum=sum;
    }
  }
  printf("%d", maxSum);
  return 0;
}
