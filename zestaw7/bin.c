#include <stdio.h>
#include <string.h>

int cnt = 0;

void rekur(char result[], char bin[], int n, int k){
    strcat(result,bin);
    if (n == 0) {
        cnt ++;
        if (cnt == k) {
            printf("%s", result);
            return;
        }
        return;
    }
    rekur(result,"0",n-1,k);
    rekur(result,"1",n-1,k);
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    rekur("","0",n-1,k);
    rekur("","1",n-1,k);
}