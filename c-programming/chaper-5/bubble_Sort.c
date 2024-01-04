/* Bubble Sort: */

#include <stdio.h>
#include <stdlib.h>

#define MEM_OUT_ERR -1

void bubbleSort(int *arr, int size);
void swap(int *a, int *b);

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

    bubbleSort(arr, size);
    printf("\n After sort: ");
    for( i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if( arr[i] > arr[j]){
                swap(arr + i, arr + j);
                // swap(&arr[i], &arr[j]);
            }
        }
    }
    return;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}