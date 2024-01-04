#include <stdio.h>

void strCpy(char *from, char *to){
    while((*to++ = *from++) != '\0');
    return;
}

int main(){
    char paragraph[100] = "I am vinay.";
    char paragraph_copy[100];

    printf("%s", paragraph);
    printf("\nBefore copy: ");
    printf("%s", paragraph_copy);
    printf("//////////////////////////");

    strCpy(paragraph, paragraph_copy);
    printf("\nAfter copy: ");
    printf("%s", paragraph_copy);
    printf("//////////////////////////");

    return 0;

}