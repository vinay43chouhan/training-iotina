#include<stdio.h>
#include<stdlib.h>
/*One of the method to sort the unsorted array*/

int main(){
    int n;
    printf("Enter number of element you want to enter: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n,sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Your array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            for(int j = i-gap; j >= 0 && arr[j] > arr[j+gap]; j-=gap){
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
        }
    }
    printf("Your sorted array: ");

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}