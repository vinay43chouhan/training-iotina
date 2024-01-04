/* Selection Sort: */
#include <stdio.h>
#include <stdlib.h>

#define MEM_OUT_ERR -1

void selectionSort(int *arr, int size);

int main(){
    int size = 0;
    int *arr = NULL;
    int i = 0;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));
    if(arr == NULL){
        return MEM_OUT_ERR;
    }
    printf("\nEnter elements of the array: ");
    for( i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("\n Before sort: ");
    for( i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    selectionSort(arr, size);
    printf("\n After sort: ");
    for( i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void selectionSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        int minimum_element_onward = arr[i];
        int j = i + 1;
        int index = i;
        while (j < size){
            if(minimum_element_onward > arr[j]){
                minimum_element_onward = arr[j];
                index = j;
            }
            j++;
        }
        if( i != index){
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
    return;
}

