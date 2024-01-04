/* Two Pointer approach */
#include<stdio.h>

void reverseString(char *paragraph, int len);

int main(){
    char *paragraph = NULL;
    size_t len = 0;

    int length = getline(&paragraph, &len, stdin);
    
    int i = 0;
    // int length = 0;
    while(paragraph[i] != '\0'){
        printf("%c", paragraph[i]);
        i++;
        // length++;
    }

    reverseString(paragraph, length);
    i = 0;
    while(paragraph[i] != '\0'){
        printf("%c", paragraph[i]);
        i++;
    }
    printf("\n");
    return 0;
}

void reverseString(char *paragraph, int len){
    int starting_index = 0;
    int ending_index = len - 1;

    while (starting_index < ending_index){
        char temp = paragraph[starting_index];
        paragraph[starting_index] = paragraph[ending_index];
        paragraph[ending_index] = temp;
        starting_index++;
        ending_index--;
    }
    return;
}