#include <stdio.h>

int findMin(int A[],int n, int k, int sum){
    if (k == 0){
        return sum;
    }
    int best = A[0];
    int best_idx = 0; 
    for(int i=0;i<n;i++){
        if (A[i] > best) {
            best = A[i];
            best_idx = i;
        }
    }
    A[best_idx] = A[best_idx]/2;
    return findMin(A,n,k-1,sum - (best - A[best_idx]));
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int A[n];
    int sum = 0;
    for (int i=0;i<n;i++){
        scanf("%d", &A[i]);
        sum += A[i];
    }
    printf("%d", findMin(A,n,k,sum));

    return 0;
}