#include <stdio.h>

void printlist(int A[],int n){
    for (int i=0; i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d" , &n);
    int A[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &A[i][j]);
        }
    }
    int B[n]; // index array
    for (int i=0; i<n;i++){
        B[i] = 0;
    }
    int C[n*n];
    int j = 0;
    int prev = -1;
    int ile_liczb = 0;
    while (j < n*n){
        int min = 99999;
        int idx;
        int finish = 1;
        for (int k=0;k<n;k++){
            if (B[k] < n){
                if(A[k][B[k]] < min) {
                    min = A[k][B[k]];
                    idx = k;
                }
                finish = 0;
            }
        }
        if (finish == 1) break;

        if (min == prev){
            B[idx] += 1;
        }
        else{
            B[idx] += 1;
            C[j] = min;
            prev = min;
            j += 1;
            ile_liczb += 1;
        }
    }
    printlist(C,ile_liczb);
}