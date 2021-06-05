#include <stdio.h>

int half(int t[],int sum,int n){
    int new_sum;
    for(int i=0; i<n; i++){
        new_sum =0;
        sum -= t[i];
        if (sum%2 == 0){
            for (int j=0; j<i;j++){
                new_sum += t[j];
            }
            if (new_sum == sum/2){
                return i;
            }
        }
        sum += t[i];
    }
    return n;
}

int main(){
    int n,sum = 0;
    scanf("%d", &n);
    int t[n];
    for (int i=0;i<n;i++){
        scanf("%d", &t[i]);
        sum += t[i];
    }
    int result = half(t,sum,n);
    if (result < n){
        printf("%d", result);
    }
}
