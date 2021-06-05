#include <stdio.h>
#include <malloc.h>

void printA(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    char num[31];
    scanf("%s", &num);
    int last;
    int *N1 = calloc(31, sizeof(int *));
    int *N2 = calloc(31, sizeof(int *));
    for(int i=0;i<31;i++){
        if (num[i] == NULL) {
            last = i-1;
            break;
        }
        else {
            if (num[i] == '0'){
                N1[i] = 0;
                N2[i] = 0;
            }
            else if (num[i] == '1') {
                N1[i] = 1;
                N2[i] = 1;
            }
            else if (num[i] == '2'){
                N1[i] = 2;
                N2[i] = 2;
            }
            else if (num[i] == '3') {
                N1[i] = 3;
                N2[i] = 3;
            }
            else if (num[i] == '4') {
                N1[i] = 4;
                N2[i] = 4;
            }
            else if (num[i] == '5') {
                N1[i] = 5;
                N2[i] = 5;
            }
            else if (num[i] == '6') {
                N1[i] = 6;
                N2[i] = 6;
            }
            else if (num[i] == '7') {
                N1[i] = 7;
                N2[i] = 7;
            }
            else if (num[i] == '8') {
                N1[i] = 8;
                N2[i] = 8;
            }
            else if (num[i] == '9') {
                N1[i] = 9;
                N2[i] = 9;
            }
        }
    }

    int *B = calloc(100, sizeof(int *));

    int minus = 0;
    for (int i=0;i<100;i++){
        B[i] = N1[last] % 2;
        if (minus == 0){
            N1[last] -= B[i];
        }else{
            N1[last] += B[i];
        }
        int x = 0;
        for(int i=0;i<31;i++){
            x += N1[i];
            N1[i] = x/2;
            x -= (x/2)*2;
            x *= 10;
        }
        if (minus == 0) minus = 1;
        else minus = 0;
    }
    if(N1[last] > 0) {
        printf("NO\n");
    }
    else{
        for (int i=0;i<100;i++){
            if (B[i] == 1) printf("%d ", i);
        }
        printf("\n");
    }

    int *C = calloc(100, sizeof(int *));
    minus = 1;
    for (int i=0;i<100;i++){
        C[i] = N2[last] % 2;
        if (minus == 0){
            N2[last] -= C[i];
        }else{
            N2[last] += C[i];
        }
        int x = 0;
        for(int i=0;i<31;i++){
            x += N2[i];
            N2[i] = x/2;
            x -= (x/2)*2;
            x *= 10;
        }
        if (minus == 0) minus = 1;
        else minus = 0;
    }
    if(N2[last] > 0) printf("NO");
    else{
        for (int i=0;i<100;i++){
            if (C[i] == 1) printf("%d ", i);
        }
        printf("\n");
    }
}