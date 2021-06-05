#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int T[n][n];
    for (int i=0;i < n;i++){
        for (int j=0;j<n;j++){
            scanf("%d" , &T[i][j]);
        }
    }
    // poziom
    int best = T[0][0] + T[0][1];
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            int idx = j;
            int suma = 0, cnt = 0;
            while (cnt < k){
                if (idx >= n)idx = idx%n;
                suma += T[i][idx];
                idx ++;
                cnt ++;
            }
            if (suma > best && cnt == k) best = suma;
        }
    }
    // pion
    for (int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            int idx = j;
            int cnt = 0, suma = 0;
            while (cnt < k){
                if (idx >= n)idx = idx%n;
                suma += T[idx][i];
                idx ++;
                cnt ++;
            }
            if (suma > best && cnt == k) best = suma;
        }
    }
    // prawo dol
    for (int i = 0;i<n;i++){
        for (int j = 0;j < n; j++){
            int idx_w = i;
            int idx_k = j;
            int cnt = 0, suma = 0;
            while (cnt < k){
                if (idx_k >= n){
                    idx_k = idx_k%n;
                }
                if (idx_w >= n){
                    idx_w = idx_w%n;
                }

                suma += T[idx_w][idx_k];
                idx_w ++;
                idx_k ++;
                cnt ++;
            }
            if (suma > best && cnt == k) best = suma;
        }
    }
    //lewo dol
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            int idx_w = i;
            int idx_k = j;
            int cnt = 0, suma = 0;
            while (cnt < k){
                if (idx_k == -1){
                    idx_k = n - 1;
                }
                if (idx_w >= n){
                    idx_w = idx_w%n;
                }
                suma += T[idx_w][idx_k];
                idx_w ++;
                idx_k --;
                cnt ++;
            }
            if (suma > best && cnt == k) best = suma;
        }
    }
    printf("%d", best);
}