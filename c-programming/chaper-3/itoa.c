#include<stdio.h>

int main(){
    int number;
    int positive = 1;
    printf("Enter a number to convert in string: \n");
    scanf("%d", &number);
    int len = 0;
    if(number < 0){
        number = -number;
        positive = 0;
    }
    int num = number;
    while(number > 0){
        number /= 10;
        len++;
    }
    if(positive == 0){
        len += 2;
    }else{
        len += 1;
    }
    char number_in_string_format[len];

    number = num;
    int  i = len-1;
    if(positive == 0){
        number_in_string_format[0] = '-';
    }
    number_in_string_format[i] = '\0';
    while(number > 0){
        number_in_string_format[--i] = (number % 10 + '0');

        number/=10;
    }
    for(int j = 0; number_in_string_format[j] != '\0'; j++){
        printf("%c", number_in_string_format[j]);
    }
    printf("\n %d \n", sizeof(number_in_string_format));
    return 0;
}
