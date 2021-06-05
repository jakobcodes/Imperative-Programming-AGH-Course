#include <stdio.h>
#include <malloc.h>

int main(){
    int n;
    scanf("%d",&n);
    int **T;
    T = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++){
        T[i] = malloc(n * sizeof(int));
    }
    int a = 1, w = 0, k = n-1;
    while (w < k){
        for(int i=w;i <= k; i++) T[w][i] = a++;

        for(int j=w+1;j <= k; j++) T[j][k] = a++;

        for(int i=k-1;i >= w; i--) T[k][i] = a++;

        for(int j=k-1;j >= w+1; j--) T[j][w] = a++;
        w++;
        k--;
    }
    if (w == k){
        T[w][k] = a;
    }
    for(int i=0;i < n;i++){
        for (int j=0;j < n; j++){
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++){
        free(T[i]);
    }
    free(T);

}