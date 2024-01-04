#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Global counters
unsigned long long int operationCounter = 0;
unsigned long long int nlognCounter = 0;

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    operationCounter += 3; // Increment counter for three assignments
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        operationCounter++; // Increment counter for each comparison
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Test array
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15, 17, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Size\tOperations\tn log n\n");

    // Measure the growth rate of operations
    for (int i = 1; i <= n; i++) {
        operationCounter = 0;

        // Perform Quicksort
        quicksort(arr, 0, i - 1);

        // Calculate n log n
        nlognCounter = i * (unsigned long long int)(log2(i));

        // Display the input size, the number of operations, and n log n
        printf("%d\t\t%llu\t\t%llu\n", i, operationCounter, nlognCounter);
    }

    return 0;
}

