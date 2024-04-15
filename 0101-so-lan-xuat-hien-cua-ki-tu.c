#include <stdio.h>
int main(){
    char a[1000]={ };
    int dem=0;
    fgets(a,sizeof(a),stdin);
    for (int i='a';i<='z';i++){
        for(int j=0;j<=999;j++){
            if(i==a[j]) dem+=1;
        }
        if(dem!=0) printf("The letter '%c' appears %d time(s).\n",i,dem);
        dem=0;
    }
}