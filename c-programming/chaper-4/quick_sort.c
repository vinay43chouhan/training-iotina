/* Quick Sort: One of the sorting algorithm based on divide and conquer Time Complexity: nlogn */

#include <stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
    return;
}

int partition(int *arr, int start_index, int end_index){
    int pivot = arr[start_index];
    int left = start_index;
    int right = end_index;
    int count_numbers_greater_then_equal_pivot = 0;

    for (int i = start_index+1; i <= end_index; i++){
        if(arr[i] <= pivot){
            count_numbers_greater_then_equal_pivot++;
        }
    }

    int partition_index = start_index + count_numbers_greater_then_equal_pivot;
    swap(&arr[start_index], &arr[partition_index]);

    while (left < partition_index && partition_index < right){
        while (arr[left] <= pivot){
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }
        if(left < partition_index && right > partition_index){
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    return partition_index;
    
}

void quickSort(int* arr, int start_index, int end_index){
    if(start_index >= end_index){
        return;
    }
    int partition_index = partition(arr, start_index, end_index);
    quickSort(arr, start_index, partition_index-1);
    quickSort(arr, partition_index+1, end_index);
    return;
}

int main(){
    int i = 0;
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int*)calloc(size, sizeof(int));
    if(array == NULL){
        printf("Memory is not allocate.\n");
        return 0;
    }

    printf("Enter %d number: ", size);
    for(i = 0; i < size; i++){
        scanf("%d",&array[i]);
    }
    quickSort(array, 0, size - 1);
    printf("\n Your sorted array: ");
    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}