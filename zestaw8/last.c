#include <stdio.h>

long long cntSum(long long x){
    long long sum = 0;
    while (x > 0){
        sum += x;
        x /= 10;
    }
    return sum;
}

int main(){
    long long s;
    scanf("%lld", &s);

    long long prob = 0.9 * s;
    int xd = 0;
    for (long long i=prob-100; i < prob + 100; i++){
        if  (cntSum(i) == s){
            printf("%lld", i);
            xd = 1;
            break;
        }
    }
    if (xd == 0){
        printf("%d", -1);
    }
}