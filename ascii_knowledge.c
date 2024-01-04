/*ASCII Range 0 - 255*/
/* ASCII value of 0 to 9 - [48, 57]*/
/* ASCII value of a to z - [97, 122]*/
/* ASCII value of A to Z - [65, 90]*/
#include<stdio.h>

int main(){
    int num = 48; // the integer 48 will store as binary in memory
    char ch = num; // the ch will store ascci value of it
    printf("%d \n %c \n", num, num);
    printf("%d \n %c \n", ch , ch);

    int A = 'A';
    printf("%d \n %c \n", A , A);
    int Z = 'Z';
    printf("%d \n %c \n", Z , Z);

    int a = 'a';
    printf("%d \n %c \n", a , a);
    int z = 'z';
    printf("%d \n %c \n", z , z);
    return 0;
}
