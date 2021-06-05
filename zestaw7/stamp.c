#include <stdio.h>

int main(){
    int n,k,l;
    scanf("%d %d %d", &n , &k, &l);
    int T[n][n];
    for (int i=0;i < n;i++){
        for (int j=0;j<n;j++){
            scanf("%d" , &T[i][j]);
        }
    }
    int P[k][l];
    for (int i=0;i < k;i++){
        for (int j=0;j<l;j++){
            scanf("%d" , &P[i][j]);
        }
    }
    int best = T[0][0];
    for (int i=0;i<=n-k;i++){
        for (int j=0;j<=n-l;j++){
            int suma=0;
            for (int x=0;x<k;x++){
                for (int y=0;y<l;y++){
                    if (P[x][y] == 1) suma += T[i+x][j+y];
                }
            }
            if (suma > best) best = suma;
        }
    }
    printf("%d", best);
}