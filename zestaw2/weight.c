#include <stdio.h>

int weight(int n, int w, int t[]){
    if (w == 0){
        return 1;
    }
    if (n == -1){
        return 0;
    }
    return  (weight(n-1,w-t[n],t) || 
            (weight(n-1,w+t[n],t) == 1) || 
            (weight(n-1,w,t) == 1));

    return 0;
}

int main(){
    int n,w;
    scanf("%d %d\n", &n, &w);
    int t[n];
    int suma;
    for(int i=0;i<n;i++){
        scanf("%d", &t[i]);
        suma += t[i];
    }

    if (suma >= w){
        if (weight(n-1,w,t) == 1){
            printf("YES");
        }
        else{
            printf("NO");
        }
    }
    else{
        printf("NO");
    }
    return 0;
}