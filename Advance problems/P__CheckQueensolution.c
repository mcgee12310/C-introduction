#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int ketqua[n];
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        int s[a][a];
        for(int j=0; j<a; j++){
            for(int k=0; k<a; k++){
                scanf("%d", &s[j][k]);
            }   
        }
        ketqua[i]= 1;
        for(int j=0; j<a; j++){
            for(int k=0; k<a; k++){
                if(s[j][k]==1){
                    for(int m=0; m<a; m++){
                        if(s[m][k]==1 && m!=j) ketqua[i]= 0;
                        if(s[j][m]==1 && m!=k) ketqua[i]= 0;
                    }
                    int m=j+1;
                    int n=k+1;
                    while(m<a&&n<a&&m>=0&&n>=0){
                        if(s[m][n]==1) ketqua[i]= 0;
                        m++;
                        n++;
                    }
                    m=j-1; n=k-1;
                    while(m<a&&n<a&&m>=0&&n>=0){
                        if(s[m][n]==1) ketqua[i]= 0;
                        m--;
                        n--;
                    }
                    m=j+1; n=k-1;
                    while(m<a&&n<a&&m>=0&&n>=0){
                        if(s[m][n]==1) ketqua[i]= 0;
                        m++;
                        n--;
                    }
                    m=j-1; n=k+1;
                    while(m<a&&n<a&&m>=0&&n>=0){
                        if(s[m][n]==1) ketqua[i]= 0;
                        m--;
                        n++;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++) printf("%d\n", ketqua[i]);
}