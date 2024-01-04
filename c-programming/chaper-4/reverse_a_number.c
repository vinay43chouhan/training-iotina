/* We are reversing a number like if number is 1234 then 4321*/

#include <stdio.h>

int reverse(int number) {
    if (number == 0) {
        return 0;
    }

    int lastDigit = number % 10;
    int remainingDigits = number / 10;

    int reversedNumber = reverse(remainingDigits);
    int position = 1;
    int temp = reversedNumber;
    while (temp > 0) {
        temp /= 10;
        position *= 10;
    }
    return  lastDigit * position + reversedNumber;
}

int main() {
    int number = 0;
    int sign = 1;

    printf("Enter a number: ");
    scanf("%d", &number);
    
    if(number < 0){
        sign = -1;
        number = -number;
    }

    int reversedNumber = reverse(number);

    printf("Reversed number is: %d\n", sign * reversedNumber);

    return 0;
}

