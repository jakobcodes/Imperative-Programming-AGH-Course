#include <stdio.h>
#include <stdlib.h>

int check_distance(int i,int j, int w, int k, int r){
    int distance;
    int x = abs(i-w);
    int y = abs(j-k);
    if (x > y) distance = x;
    else distance = y;

    if (distance <= r) return 1;
    return 0;
}

int main(){
    int n,r;
    scanf("%d %d", &n, &r);
    int B[n][n];
    int A[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &A[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int ile = 0;
            for (int w=0;w<n;w++){
                for (int k=0;k<n;k++){
                    if (check_distance(i,j,w,k,r) == 1){
                        if (A[w][k] == 1) ile += 1;
                    }
                }
            }
            B[i][j] = ile;
        }   
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}