#include <stdio.h>
#include <string.h>

int isPrime(n){
    if (n==2 || n == 3) return 1;
    for (int i=2;i<n;i++){
        if (n%i == 0) return 0;
    }
    return 1;
}

int main(){
    char s[50];
    scanf("%s", &s);

    int n = strlen(s);

    char best = s[0];
    for (int i=0;i<n;i++){
        if (s[i] < best){
            best = s[i];
        }
    }

    char new[n];
    char min[n];
    int p = 2;
    for (int i=0;i<n;i++){
        min[i] = 'z';
    }
    for (int o=0;o<n;o++){
        if (s[o] == best) {
            for (int p = 2; p < n; p++) {
                if (isPrime(p) == 1) {
                    for (int i = 0; i < n; i++) {
                        new[i] = s[(o + (i * p)) % n];
                    }
                    if (strcmp(new, min) < 0) {
                        strcpy(min, new);
                    }
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        printf("%c", min[i]);
    }
}