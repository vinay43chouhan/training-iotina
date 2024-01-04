#include <stdio.h>

#define swap(t, a, b)   {t temp = a; a = b; b = temp;}

int main() {
    int a1 = 2;
    int b1 = 3;

    printf("%d\t%d\n", a1, b1);  

    swap(int, a1, b1);

    printf("%d\t%d\n", a1, b1);

    float a2 = 5.13;
    float b2 = 4.12;

    printf("%f\t%f\n", a2, b2);  

    swap(float, a2, b2);

    printf("%f\t%f\n", a2, b2);

    char c1 = 'z';
    char c2 = 'x';

    printf("%c\t%c\n", c1, c2);  

    swap(char, c1, c2);

    printf("%c\t%c\n", c1, c2);


    return 0;
}
