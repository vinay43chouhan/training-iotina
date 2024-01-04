#include <stdio.h>
#include <string.h>


int leftOccurenceAtPosition(char string[], char search_char);
int rightOccurenceAtPosition(char string[], char search_char);

int main(){
    char *str = NULL;
    char character_to_search;
    size_t len = 0;
    

    printf("Enter a sentence: ");
    getline(&str, &len, stdin);

    while(1){
        printf("\nEnter a character, else if you want to exit \n please enter '.'");
        scanf("%c", &character_to_search);
        getchar(); // to consume newline character
        if(character_to_search == '.'){
            break;
        }
        printf("character is %c\n", character_to_search);

        int index_from_left = leftOccurenceAtPosition(str, character_to_search);
        printf("\nLeftmost position of this character is %d\n", index_from_left);

        int index_from_right = rightOccurenceAtPosition(str, character_to_search);
        printf("\nRightmost position of this character is %d\n", index_from_right);

    }
    return 0;

}

int leftOccurenceAtPosition(char string[], char search_char){
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] == search_char){
            return i+1;
        }
        i++;
    }
    return -1;
}

int rightOccurenceAtPosition(char string[], char search_char){
    int i = strlen(string)-1;
    while(i>=0){
        if(string[i] == search_char){
            return i+1;
        }
        i--;
    }
    return -1;
}