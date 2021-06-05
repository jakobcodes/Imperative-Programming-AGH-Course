#include <stdio.h>
#include <math.h>

int power(int x, int p){
    int y = x;
    for (int i=1;i<p;i++) y = y*x;
    return y;
}

void printNumber(int m, int b){
    if (m > 0){
        printNumber(m/b,b);
        if (m%b < 10){
            printf("%d", m%b);
        }
        else if (m%b == 10){
            printf("A");
        }
        else if (m%b == 11){
            printf("B");
        }
        else if (m%b == 12){
            printf("C");
        }
        else if (m%b == 13){
            printf("D");
        }
        else if (m%b == 14){
            printf("E");
        }
        else if (m%b == 15){
            printf("F");
        }
    }
    
}

int narc(int num,int b,int m){
    int rest;
    int liczba = num;
    int suma = 0;

    while (liczba > 0){
        rest = liczba%b;
        liczba = liczba/b;
        suma += power(rest,m);
    }
    if (suma == num) {
        printNumber(num,b);
        printf(" ");
        return 1;
    }
    return 0;
}

int main(){
    int m,b,xd = 0;
    scanf("%d %d", &m, &b);
    for (int i=power(b,m-1);i<power(b,m);i++){
        if (narc(i,b,m) == 1) xd = 1;
    }
    if (xd == 0) printf("NO");
}