#include<stdio.h>

int main(){
    char number[7] = "778249";
    int i =0;
    long answer = 0;
    while(number[i]!='\0'){
        answer = answer * 10 + (number[i] - '0');
        i++;
    }
    printf("answer= %ld", answer);
    return 0;
}