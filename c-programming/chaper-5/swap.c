#include<stdio.h>

void swap(int *f, int *s){
    int temp = *f;
    *f = *s;
    *s = temp;
    return;
}

int main(){
    int first_number = 0;
    int second_number = 0;

    printf("Enter your first number: ");
    scanf("%d", &first_number);

    printf("Enter your second number: ");
    scanf("%d", &second_number);
    printf("First Number: %d\nSecond Number: %d\n", first_number, second_number);
    swap(&first_number, &second_number);
    printf("First Number: %d\nSecond Number: %d\n", first_number, second_number);

    return 0;
}