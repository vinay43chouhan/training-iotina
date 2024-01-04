/* We are reversing string using recursion*/
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void reverse(char *paragraph, int start, int end){
    if(start >= end ){
        return;
    }
    swap(&paragraph[start], &paragraph[end]);
    start++;
    end--;
    reverse(paragraph, start, end);

    return;
}
int main(){
    char *paragraph = NULL;
    size_t len = 0;
    printf("Enter a sentance: ");
    getline(&paragraph, &len, stdin);
    int e = strlen(paragraph) - 1;
    reverse(paragraph, 0, e-1);
    printf("%s", paragraph);

    return 0;
}