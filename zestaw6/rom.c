#include <stdio.h>
#include <string.h>

int convertToDec(char num[]){
    int number = 0;
    int n = strlen(num);
    for (int i=0;i<n;i++){
        if (num[i] == 'I'){
            if (num[i+1] == 'V') {number += 4;i++;}
            else if (num[i+1] == 'X') {number += 9;i++;}
            else number += 1;
        }
        else if (num[i] == 'X'){
            if (num[i+1] == 'L') {number += 40;i++;}
            else if (num[i+1] == 'C') {number += 90;i++;}
            else number += 10;
        }
        else if (num[i] == 'C'){
            if (num[i+1] == 'D') {number += 400;i++;}
            else if (num[i+1] == 'M'){ number += 900;i++;}
            else number += 100;
        }
        else if (num[i] == 'V') number += 5;
        else if (num[i] == 'L') number += 50; 
        else if (num[i] == 'D') number += 500; 
        else if (num[i] == 'M') number += 1000; 
    }
    return number;
}
void printInRom(int number){
    int num[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char *sym[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(number>0)
    {
        int div = number/num[i];
        number = number%num[i];
        while(div--)
        {
            printf("%s",sym[i]);
        }
        i--;
    }
}

int main(){
    char num1[100],num2[100];
    scanf("%s %s", num1, num2);
    int number1 = convertToDec(num1);
    int number2 = convertToDec(num2);
    int suma = number1 + number2;
    printInRom(suma);
    return 0;
}