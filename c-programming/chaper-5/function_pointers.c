#include <stdio.h>

typedef void (*Swap)(void *, void *);


void swap_generic(void *a, void *b, Swap swap){
    return swap(a, b);
}
void swap_int(int *a, int *b);
void swap_char(char *a, char *b);

int main(){
    char ch1 = 'a';
    char ch2 = 'b';
    int a = 10;
    int b = 20;
    
    swap_generic(&a, &b, swap_int);
    swap_generic(&ch1, &ch2, swap_char);

    printf("a: %d ---- b: %d", a, b);
    printf("ch1: %c ---- ch2: %c", ch1, ch2);
    
    return 0;
}

void swap_int(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swap_char(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
    return;
}