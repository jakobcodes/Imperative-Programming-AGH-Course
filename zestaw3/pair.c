#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Porównywacz
int my_compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

int pair(int A[],int n,int k){

    int count = 0;
    for (int i=0;i<n;){
        int count_numbers = 0;
        int j = i;
        while (j != n && A[i] == A[j]){
            j ++;
            count_numbers ++;
        }
        if (i != 0 && A[i-1] >= A[i] - k){
            count += count_numbers;
        }
        else if (j != n && A[j] <= A[j-1] + k){
            count += count_numbers;
        }
        i = j;
    }
    return count;
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int *A = (int *) calloc(n, sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), my_compare);
    printf("%d",pair(A,n,k));
    return 0;
}