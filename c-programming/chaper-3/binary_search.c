#include<stdio.h>
#include<stdbool.h>
#include<time.h>

bool binarySearch (int number, int size, int arr[]);

int  main(){
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));
    if (!arr) {
        printf("Malloc failed");
        return -1;
    }
    memset(arr, 0, sizeof(n*sizeof(int)));

    printf("Enter the %d elements in ascending order of the array: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n-1; i++){
        if (arr[i+1] < arr[i]) {
            printf("Array should be in ascending order");
            return -1;
        }
    }

    // TODO check the list should be ascending order
    int searching_number;
    printf("Enter the number, you want to search: \n");
    scanf("%d", &searching_number);
    
    clock_t startTime = clock();
    bool isPresent = binarySearch(searching_number, n, arr);
    clock_t endTime = clock();
    double time_taken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC * 1000;
    printf("%d is Present: %d and time taken in milliseconds: %f\n", searching_number, isPresent, time_taken);

    return 0;
}

bool binarySearch (int number, int size, int arr[]){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == number){
            return true;
        }else if (arr[mid] < number){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    
    return false;
}