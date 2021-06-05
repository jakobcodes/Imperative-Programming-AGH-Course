#include <stdio.h>
#include <string.h>

int main() {
    char word[51];
    scanf("%s", word);
    int length = strlen(word);
    char best;
    int idx = 0;
    int pos;
    int count;
    while (idx < length){
        best = 'a';
        for (int i=idx; i < length; i++){
            if (word[i] > best) {
                best = word[i];
                pos = i;
                count = 1;
            }
            else if (word[i] == best) {
                count ++;
                pos = i;
            }
        }
        for (int i=0;i<count;i++){
            printf("%c", best);
        }
        idx = pos+1;
        count = 0;
    }
}