#include <stdio.h>
#include <string.h>

int find_max(int a[], int n){
    int max=-1000;
    for(int i=0; i<n; i++){
        if(a[i]>max) max=a[i];
    }
    return max;
}

int find_min(int a[], int n){
    int min=1000;
    for(int i=0; i<n; i++){
        if(a[i]<min) min=a[i];
    }
    return min;
}

int find_max_segment(int a[], int m, int n){
    int max=-1000;
    for(int i=m-1; i<n; i++){
        if(a[i]>max) max=a[i];
    }
    return max;
}

int sum(int a[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    return sum;
}

int main(){ 
    int n;
    scanf("%d", &n);
    int a[n], ketqua[1000000], b=0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    char com[17];
    scanf("%s", &com);
    if(strcmp(com, "*")==0){
        while(strcmp(com, "***")!=0){
            scanf("%s", &com);
            if(strcmp(com, "find-max")==0) ketqua[b]=find_max(a, n);
            if(strcmp(com, "find-min")==0) ketqua[b]=find_min(a, n);
            if(strcmp(com, "sum")==0) ketqua[b]=sum(a, n);
            if(strcmp(com, "find-max-segment")==0){
                int x, y;
                scanf("%d %d", &x, &y);
                ketqua[b]=find_max_segment(a, x, y);
            }
            b++;
        }
    }  
    for(int i=0; i<b-1; i++){
        printf("%d\n", ketqua[i]);
    }
}