#include <stdio.h>
#include <stdlib.h>

int check(int i, int j, int A[]){
    int minx, miny, maxx, maxy;
    if (A[0] < A[2]) {
        minx = A[0];
        maxx = A[2];
    }
    else{
        minx = A[2];
        maxx = A[0];
    }
    if (A[1] < A[3]){
        miny = A[1];
        maxy = A[3];
    }
    else{
        miny = A[3];
        maxy = A[1];
    }
    if (i >= minx && i <maxx && j >= miny && j < maxy) return 1;
    return 0;

}

int main(){
    int n;
    scanf("%d", &n);
    int A[n][4];
    int maxx = 0, maxy = 0;
    for (int i=0;i<n;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        A[i][0] = x1;
        A[i][1] = y1;
        A[i][2] = x2;
        A[i][3] = y2;
        if (x1 > maxx) maxx = x1;
        if (x2 > maxx) maxx = x2;
        if (y1 > maxy) maxy = y1;
        if (y2 > maxy) maxy = y2;
    }
    int diff = 100;
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++){
            A[i][j] += diff;
        }
    }
    int max;
    if(maxx > maxy) max = maxx + diff;
    else max = maxy + diff;
    int countBlack = 0;
    for (int i=0;i<=max;i++){
        for (int j=0;j<=max;j++){
            int count = 0;
            for (int k=0;k<n;k++){
                if (check(i,j,A[k]) == 1) count += 1;
            }
            if (count%2 == 1) countBlack += 1;
        }
    }
    printf("%d", countBlack);
}