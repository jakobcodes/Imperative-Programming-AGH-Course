#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int A[n+1];
    for (int i=0;i <= n; i++){
        A[i] = 0;
    }
    int x,y;
    while (m > 0){
        scanf("%d %d", &x, &y);
        A[x] ++;
        A[y] ++;
        m --;
    }

    int roznica = 0;
    for (int i=1;i<=n;i++){
        roznica += ((A[i] * (n - 1 - A[i]))/2);
    }
    int result = (n*(n-1)*(n-2)/6) - roznica;
    printf("%d", result);
    return 0;
}