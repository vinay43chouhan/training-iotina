/* Linear Search: */

#include <stdio.h>
#include <stdlib.h>

#define MEM_OUT_ERR -1
#define ELEMENT_NOT_FOUND -1;

int linear_search(int *arr, int size, int number);

int main(){
    int size = 0;
    int number = 0;
    int *search_space = NULL;
    int index = -1;
    int i = 0;

    printf("Enter the size of you search space: ");
    scanf("%d", &size);

    search_space = (int*)calloc(size, sizeof(int));
    if(search_space == NULL){
        printf("Out of memory.\n");
        return MEM_OUT_ERR;
    }
    printf("\nEnter elements of the search space: ");
    for( i = 0; i < size; i++){
        scanf("%d", &search_space[i]);
    }

    printf("\nEnter the number you want to search: ");
    scanf("%d", &number);
    
    index = linear_search(search_space, size, number);
    
    index == -1 ? printf("\nElement not found.\n") : printf("\nElement %d is present at %d index.\n", number, index);

    return 0;
}

int linear_search(int *search_space, int size, int number){
    for(int i = 0; i < size; i++){
        if(search_space[i] == number){
            return i;
        }
    }
    return ELEMENT_NOT_FOUND;
}