#include <stdio.h>
//5 6 5
//-1 -2
//1 3
//1 -2
//2 -3
//4 6
//-4 -5
//00111
//01110

int XOR(int w1, int w2){
    if (w1 == 0 && w2 == 0) return 0;
    if (w1 == 0 && w2 == 1) return 1;
    if (w1 == 1 && w2 == 0) return 1;
    if (w1 == 1 && w2 == 1) return 0;
}

int power(int x, int p){
    if (p == 0) return 1;
    int num = x;
    for(int i=1;i<p;i++){
        num *= x;
    }
    return num;
}

int binToDec(char bin[],int n){
    n--;
    int number = 0;
    for (int i=0;i<=n;i++){
        if (bin[i] == '1'){
            number += power(2,n-i);
        }

    }
    return number;
}
void printBramki(int B[][3], int m){
    for (int i=1;i<=m;i++){
        printf("%d ", B[i][2]);
    }
    printf("\n");
}

int main() {
    int n,m,last;
    scanf("%d %d %d", &n, &m, &last);

    int B[m+1][3];
    for(int i=1;i<m+1;i++){
        scanf("%d %d", &B[i][0], &B[i][1]);
        B[i][2] = -1;
    }
    char bin1[n],bin2[n];
    scanf("%s %s", bin1, &bin2);

    int min,max;
    min = binToDec(bin1,n);
    max = binToDec(bin2,n);

    int count = 0;
    for (int i=min;i<=max;i++){
        int run = 1;
        while(run){
            run = 0;
            for (int b=1;b<=m;b++){
                if (B[b][2] == -1){
                    run = 1;
                    int w1 = B[b][0];
                    int w2 = B[b][1];
                    if (w1 > 0 && B[w1][2] == -1){
                        continue;
                    }
                    if (w2 > 0 && B[w2][2] == -1){
                        continue;
                    }
                    if (w1 < 0){
                        int wej = w1*(-1);
                        if (i & (power(2,n-wej))){
                            w1 = 1;
                        }else w1 = 0;
                    }else {
                        w1 = B[w1][2];
                    }
                    if (w2 < 0){
                        int wej = w2*(-1);
                        if (i & (power(2,n-wej))){
                            w2 = 1;
                        }else w2 = 0;
                    }else{
                        w2 = B[w2][2];
                    }
                    B[b][2] = XOR(w1,w2);
                }
            }
        }
        if (B[last][2] == 1) count++;
        for (int j=1;j<=m;j++){
            B[j][2] = -1;
        }
    }
    printf("%d",count);
}