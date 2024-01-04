#include<stdio.h>

int main(){
    int entered_character;
    int lower_character=0, upper_character=0, number_count=0, num_of_whitespace=0, number_of_special_sysbol=0;
    while((entered_character = getchar()) != EOF){
        printf("%d\t %c\n", entered_character, entered_character);
        if(entered_character >= 48 && entered_character<=57){
            number_count++;
        }else if (entered_character>=97 && entered_character <= 122){
            lower_character++;
        }else if (entered_character>=65 && entered_character <= 90){
            upper_character++;
        }else if (entered_character == ' '){
            num_of_whitespace++;
        }else
        {
            number_of_special_sysbol++;
        }
        
    }
    printf("You have enter %d numberrs, %d lower character %d upper character %d white space and, %d special character", number_count, lower_character, upper_character, num_of_whitespace, number_of_special_sysbol);
    return 0;
}