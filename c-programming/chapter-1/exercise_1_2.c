#include<stdio.h>
int main(){
    int integers = 56;
    char characters = 'd';
    float floating_point = 3.235467;
    char string[] = "Hi, Vinay";

    printf("%d \n %c \n %f \n %.2f \n %.4f \n %s", integers, characters, floating_point, floating_point, string);
    return 0;
}