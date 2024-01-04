/*EOF condition is often encountered by pressing a specific key combination, 
such as Ctrl+D (on Unix/Linux systems) 
or Ctrl+Z (on Windows systems), depending on the platform. noramly EOF is -1*/

#include<stdio.h>

int main(){
    char ch;

    while((ch = getchar()) != EOF){
        printf("Hi, Vinay, How are you? \n");
        // Verify that the expression getchar() != EOF is 0 or 1
        putchar(ch);
    }
    int c = ch;
    printf("%d", c);
    return 0;
}