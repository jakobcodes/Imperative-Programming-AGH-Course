#include <stdio.h>
#include <string.h>

void rekur(char res[], char bin, int n){
    if (n == 0){
        printf("%s\n", res);
        return;
    }
    strcat(res,bin);
    if (bin == '0'){
        rekur(res,'0',n-1);
        rekur(res,'1',n-1);
    }
    else{
        rekur(res,'0',n-1);
    }
    
    
}

int main(){
    int n = 3;
    char xd[] = "";
    char xp[] = "";
    rekur(xd,'0',n-1);
    rekur(xp,'1',n-1);
}