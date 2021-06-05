#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[200] = {0};
    int n;
    scanf("%d", &n);
    int sizeOfArray = sizeof(A)/sizeof(A[0]);
    int maxLength = 1;
    A[sizeOfArray-1] = 1;
    for (int i=1;i<=n;i++){
        int j = sizeOfArray-1;
        int rest = 0;
        while(j>0){
            A[j] *= i;
            A[j] += rest;
            if (A[j] > 9){
                rest = A[j] / 10;
                A[j] = A[j] % 10;
                if (sizeOfArray - j == maxLength) maxLength += 1;
            }
            else rest = 0;
            j -= 1;
        }
    }
    for (int i=sizeOfArray-maxLength; i<sizeOfArray;i++){
        printf("%d", A[i]);
    }
}