#include <stdio.h>

int power(int x,int p){
    if (p == 0) return 1;
    int res = x;
    for (int i=1;i<p;i++){
        res *= x;
    }
    return res;
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int number;
    int count=0;

    if (m != 1) {
        for (int i = 0; i < power(2, n); i++) {
            if (i % m == 0) continue;
            number = i;
            for (int j = 0; j < n; j++) {
                if (i & (power(2, j))) {
                    number -= (power(2, j));
                    if (number % m == 0 && number != 0) {
                        count++;
                        break;
                    }
                    number += (power(2, j));
                } else {
                    number += (power(2, j));
                    if (number % m == 0 && number != 0) {
                        count++;
                        break;
                    }
                    number -= (power(2, j));
                }
            }
        }
    }
    printf("%d", count);
}