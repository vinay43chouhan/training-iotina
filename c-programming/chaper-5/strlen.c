#include <stdio.h>
#include <string.h>

int strlength(char *str);

int main(){
    char *paragraph = NULL;
    int len = 0;
    printf("Enter a paragraph: ");
    getline(&paragraph, &len, stdin);

    int length = strlength(paragraph);

    printf("length of the paragraph: %d, %d\n", length, strlen(paragraph));

    return 0;

}

int strlength(char *str){
    char *temp = str;
    int count = 0;
    while(*temp != '\0'){
        count++;
        *temp++;
        // *++str;
    }
    str[--count] = '\0';
    return count;
}
