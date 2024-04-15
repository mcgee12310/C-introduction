#include <stdio.h>
#include <math.h>
long sumcube(int n){  
    int i = 0; 
    long s = 0;
    for(i=1; i<=n; i++) s = s + i*i*i;
    return s;
}
void printsubmultiples(int n){  
    int i; 
    for(i=2; i<n; i++)
    if (n%i ==0) printf("%d ",i);
    printf("\n");
}
void printsquares(int n){  
    int i; 
    for(i=1; i<=n; i++) printf("%d ",i*i);
    printf("\n");
}