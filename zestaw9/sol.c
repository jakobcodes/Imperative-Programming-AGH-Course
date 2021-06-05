#include <stdio.h>
#include <malloc.h>

int power(int x,int p){
    if (p == 0) return 1;
    int res = x;
    for (int i=1;i<p;i++){
        res *= x;
    }
    return res;
}

int main() {
    int n,g;
    scanf("%d %d", &n, &g);

    int T[n];
    for (int i=0;i<n;i++){
        scanf("%d", &T[i]);
    }
    int num;

    int **numbers = calloc(30, sizeof (int*));
    for (int i=0;i<30;i++){
        numbers[i] = calloc(n, sizeof(int));
    }
    int last;
    for (int i=0;i<30;i++){
        if (g & power(2,i)){
            last = i;
        }
    }

    for (int i=0;i<n;i++){
        num = T[i];
        if (num <= g) {
            for (int j = 0; j < 30; j++) {
                if (num & power(2, j)) {
                    numbers[j][i] = 1;
                }
            }
        }
    }
//    for(int i=0; i<30; i++) {
//        for(int j=0; j<n; j++) {
//            printf("%d ", numbers[i][j]);
//        }
//        printf("\n");
//    }
    int best = n;
    int count;
    int xd;
    for(int i=0;i<30;i++){
        count = 0;

        if (g & power(2,i)){
            for (int j=0;j<n;j++){
                if (numbers[i][j] == 1){
                    xd = 1;
                    for (int k=0;k<30;k++){
                        if (!(g&power(2,k)) && numbers[k][j] == 1){
                            xd = 0;
                            break;
                        }
                    }
                    if(xd == 1) count++;
                }
            }
            if (count < best) best = count;
        }
    }
    printf("%d",best);
    return 0;
}