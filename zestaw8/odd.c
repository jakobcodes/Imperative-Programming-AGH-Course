#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    long long sum = 0;
    long long x,y;
    int count;
    y = n;

    if (y%2 == 0) {
        sum = sum + (y/2)*(y/2);
    }
    else{
        sum = sum + ((1+y)/2) * ((y/2)+1);
    }

    for(int i = 1;i <= n/2;i += 2){
        x = i*2;
        count = 0;
        while (x <= n){
            count = count + 1;
            x = x * 2;
        }
        sum = sum + i * count;
    }
    printf("%lld",sum);
}