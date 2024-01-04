#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = '5';
    int num = 10;

    if ((num = isdigit(ch)) != 0 ) {
        printf("%c is a digit.\n", ch);
        printf("%d is a digit.\n", num);
    } else {
        printf("%c is not a digit.\n", ch);
    }

    return 0;
}
