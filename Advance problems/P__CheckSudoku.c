#include <stdio.h>

int check(int s[9][9]){
    int sum=0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sum = sum + s[i][j];
        }
        if(sum!=45) return 0;
        sum=0;
    }
    sum=0;
    for(int j=0; j<9; j++){
        for(int i=0; i<9; i++){
            sum = sum + s[i][j];
        }
        if(sum!=45) return 0;
        sum=0;
    }
    sum=0;
    for(int i=0; i<9; i+=3){
        for(int j=i; j<i+3; j++){
            for(int k=0; k<3; k++){
                sum+=s[j][k];
            }
        }
        if(sum!=45) return 0;
        sum=0;
    }
    for(int i=0; i<9; i+=3){
        for(int j=i; j<i+3; j++){
            for(int k=4; k<7; k++){
                sum+=s[j][k];
            }
        }
        if(sum!=45) return 0;
        sum=0;
    }
    for(int i=0; i<9; i+=3){
        for(int j=i; j<i+3; j++){
            for(int k=6; k<9; k++){
                sum+=s[j][k];
            }
        }
        if(sum!=45) return 0;
        sum=0;
    }
    return 1;
}
int main(){
    int n;
    scanf("%d", &n);
    int s[9][9], ketqua[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            for(int k=0; k<9; k++){
                scanf("%d", &s[j][k]);
            }
        }
        ketqua[i]=check(s);
    }
    for(int i=0; i<n; i++) printf("%d\n", ketqua[i]);
}