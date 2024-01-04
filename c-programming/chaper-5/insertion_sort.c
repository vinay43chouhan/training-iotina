/* Insertion Sort: This is one of the sorting algorithm 
in which we break the items into two parts one is sorted and other one is unsorted
the process of sorting is take one item each time and put it into sorted part in sorted array.*/

#include <stdio.h>
#include <stdlib.h>

#define MEM_OUT_ERR -1

void insertionSort(int *arr, int size);

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

    insertionSort(arr, size);
    printf("\n After sort: ");
    for( i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void insertionSort(int *arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && (arr[j] > key)){
                arr[j+1] = arr[j];
                j--;     
        }
        arr[j + 1] = key;
    }
    return;
}
