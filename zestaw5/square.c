#include <stdio.h>

int min(int a,int b,int c,int d){
    if (a<=b && a<=c && a<=d) return a;
    else if (b<=a && b<=c && b<=d) return b;
    else if (c<=a && c<=b && c<=d) return c;
    else if (d<=a && d<=b && d<=c) return d;
    return 0;
}

int main(){
    int n,k;
    scanf("%d %d", &n ,&k);
    int T[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &T[i][j]);
        }
    }
    
    int q=0;
    int B[n*n][2];
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int r = 1;
            while (r<=min(i,j,n-i-1,n-j-1)){
                int suma = 0;
                for (int l=0;l<2*r;l++){
                    suma += (T[i-r][j-r+l] + T[i-r+l][j+r] + T[i+r][j+r-l] + T[i+r-l][j-r]);
                }
                if (suma == k){
                    B[q][0] = i;
                    B[q][1] = j;
                    q++;
                }
                r++;
            }
        }
    }
    printf("%d\n",q);
    for (int i=0;i<q;i++){
        printf("%d %d\n", B[i][0], B[i][1]);
    }

    return 0;
}
