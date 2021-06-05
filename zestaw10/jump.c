#include <stdio.h>
#include <malloc.h>

void left(int A[], int p) {
    A[p]--;
    A[p - 1]++;
    A[p - 2]++;
}

void right(int A[], int p) {
    A[p]--;
    A[p + 1]--;
    A[p + 2]++;
}

void rozladuj(int A[], int p) {
    left(A, p);
    right(A, p - 1);
    right(A, p);
}

void printA(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n, p, m;
    scanf("%d ", &n);
    int tmp[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p, &m);
        tmp[i][0] = p;
        tmp[i][1] = m;
    }
    int min = tmp[0][0];
    int maks = tmp[n-1][0];

    int len = (maks - min) + 80;
    int *A = calloc(len, sizeof(int *));

    for (int i = 0; i < n; i++) {
        A[tmp[i][0] + 40] = tmp[i][1];
    }
    // rozladowanie
    int xd = 1;
    while (xd){
        xd = 0;
        for (int i = 0; i < len; i++) {
            while (A[i] > 2) {
                xd = 1;
                rozladuj(A, i);
            }
        }
    }

    for (int i = 0; i < len; i++) {
        if (A[i] > 0) p = i;
    }
    p--;
    int run = 1;

    // faza 2
    while (run) {
        if (A[p] > 0 && A[p + 1] > 0) {
            right(A, p);
            p += 2;
        } else if (A[p] == 2 && A[p - 1] > 0) {
            p--;
        } else if (A[p] == 2 && A[p+1] == 0){
            left(A,p);
            right(A,p-1);
            p++;
        }
        else if(A[p] == 3){
            rozladuj(A,p);
            p+=2;
        }
        else{
            for(int i=0;i<len;i++){
                if (A[i] > 0) {
                    min = i;
                    break;
                }
            }
            if (p == min) {
                run = 0;
            }
            else{
                p--;
                while (A[p] == 0) p--;
            }
        }

    }
    for (int i=0;i<len;i++){
        if (A[i] == 1) printf("%d ", i-40);
    }
}