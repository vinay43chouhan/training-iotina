#include<stdio.h>
#include<string.h>

int main(){
    char paragraph[] = "Hi, My name is vinay    \n"
                        "You can call me by any name.\n\t        ";
    
    // int size = sizeof(paragraph);
    // printf("Size: %d", size);
    int size = strlen(paragraph);
    printf("Size: %d\n", size);
    int i = size-1;
    while(size>0 && i>=0 && (paragraph[i] == ' ' || paragraph[i] == '\n' || paragraph[i] == '\t')){
        i--;
    }
    if(i>=0){
        paragraph[i+1] = '\0';
    }
    printf("%s\n",paragraph);
    printf("%zu\n",strlen(paragraph));
    return 0;
}