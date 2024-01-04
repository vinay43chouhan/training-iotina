#include<stdio.h>

#define CODE 8888 // macro as variable
#define MAX(a,b) (a>=b ? a : b) // macro as function
#define MUTIPLICATION(a,b) a*b
#define MUTIPLICATION_CORRECT(a,b) (a)*(b)

int main(){
    printf("%d \n", CODE);
    printf("%d \n", MAX(5,8));
    int num1 = 9;
    int num2 = 10;
    printf("%d \n %d \n %d \n", MAX(++num1, ++num2), num1, num2); // unexpacted results due replacement
    printf("%d \n %d \n %d\n", MUTIPLICATION(num1, num2), num1, num2); // Right
    printf("%d \n %d \n %d\n", MUTIPLICATION(num1+1, num2+1), num1, num2); // Wrong
    return 0;
}