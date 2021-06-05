#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n );
    int T[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &T[i][j]);
        }
    }
    int best_P = 0;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for(int w=i+1;w<n;w++){
                for (int k=j+1;k<n;k++){
                    int new_P = (w-i+1)*(k-j+1);
                    if (new_P < best_P)continue;
                    int stop = 0;
                    for (int x=i;x<=w;x++){
                        for (int y=j;y<=k;y++){
                            if (T[x][y] == 1) {stop = 1; break;}
                        }
                        if (stop == 1) break;
                    }
                    if (stop == 0){
                        if(best_P < new_P) best_P = new_P;
                    }
                }
            }
        }
    }
    printf("%d", best_P);
}