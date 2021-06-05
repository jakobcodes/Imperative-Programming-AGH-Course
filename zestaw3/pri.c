#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check_sq(int x){
    int result = 0;
    while (1){
        result = 0;
        while(x > 0){
            int r = x%10;
            result += r*r;
            x = x/10;
        }
        x = result;
        if (x == 1 || x == 4) break;
    }
    return x;
}

int isPrime(int x){
    if (x == 1) return 0;
    for (int i=2;i<=sqrt(x);i++){
        if (x%i==0)return 0;
    }
    return 1;
}

int main(){
    int l,u,k;
    scanf("%d %d %d", &l, &u, &k);
    int count = 0;
    int last;
    for (int i=l;i<=u;i++){
        if (isPrime(i) == 1){
            if (check_sq(i) == 1){
                count ++;
                last = i;
            }
        }
        if (count == k){
            printf("%d",last);
            exit(0);
        }
    }
    printf("%d", -1);
}

