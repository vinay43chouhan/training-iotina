/* We are converting a integer to string using recursion*/
#include <stdio.h>

void convertToString(int number, char str[], int* index){
    if(number >= 0 && number <= 9){
        str[*index] = (number + '0');
        // *index = *index + 1;
        ++*index;
        return;
    }

    char current_character = ((number % 10) + '0');
    convertToString(number / 10, str, index);
    str[*index] = current_character;
    ++*index;
    return;
}
int main(){
    int number = 0;
    char str[50];
    int index = 0;

    printf("Enter a number: ");
    scanf("%d", &number);
    
    if(number < 0){
        number = -number;
        str[index++] = '-';
    }
    convertToString(number, str, &index);
    str[index] = '\0';

    printf("Converted number in string is: %s\n", str);

    return 0;
}