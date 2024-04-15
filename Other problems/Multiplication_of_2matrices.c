#include <stdio.h>

int main()
{
    int a[100][100], b[100][100], n,k,m,c=0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &k, &m);
    for(int i=0;i<k;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &b[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for(int x=0;x<k;x++){
                c = c + a[i][x]*b[x][j];
            }
            if (j==m-1) printf("%d\n", c);
            else printf("%d ", c);
            c=0;
        }
    }
}
