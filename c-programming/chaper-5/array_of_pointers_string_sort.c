/* This is the program use to sorted array of pointers that pointing array of character. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

void bubbleSort(char *array[], int size);

int  main(){
    char *array_of_string[MAXSIZE] = {NULL};
    char *line = NULL;
    int i = 0;
    int size = 0;
    int count = 0;

    while(i < MAXSIZE && printf("Enter a line: ") && (size = getline(&line, &size, stdin)) > 1){
        int length_paragraph = strlen(line);
        line[length_paragraph - 1] = '\0';
        if(strcmp(line, "done") == 0){
            printf("\nEXITED\n");
            break;
        }
        
        char *cpy_string = (char*)malloc(length_paragraph * sizeof(char));
        if( cpy_string == NULL ){
            printf("Memory is Not located.\n");
        }
        count++;
        int j = 0;
        while(line[j] != '\0'){
            cpy_string[j] = line[j];
            j++; 
        }
        cpy_string[j] = '\0';
        array_of_string[i] = cpy_string;
        printf("\nEntered line: %s", array_of_string[i]);
        i++;
        printf("\nEnter 'done' is you want to exit:\n");
    }

    bubbleSort(array_of_string, count);

    for(i = 0; i < count; i++){
        printf("%s\n", array_of_string[i]);
    }
    
    return 0;

}

void bubbleSort(char *array[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(strcmp(array[i], array[j]) > 0){
                char *add = array[i];
                array[i] = array[j];
                array[j] = add;
            }
        }
    }
    return 0;
}
