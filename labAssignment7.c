#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int bubbleSort(int arr[], int n){
    int temp;
    int count = 0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

int selectionSort(int arr[], int n){
    int minIndex = 0;
    int temp;
    int count = 0;

    for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
                count++;
            }
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    return count;
}

void swapCount(int arr[], int n){
    int count;
    for (int i=0; i<n; i++){
        count = 0;
        for (int j=i; j<n; j++){
            if(arr[j]<arr[i]){
                count++;
            }
        }
        printf("%d: # of times %d is swapped\n", count, arr[i]);
    }
}

int main(){
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size1 = 8;
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size2 = 8;

    printf("ARRAY 1: \n");
    printf("SELECTION SORT:\n");
    swapCount(array1, size1);
    printf("Total # of swaps: %d\n", selectionSort(array1, size1));

    
    int resetArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    printf("BUBBLE SORT:\n");
    swapCount(resetArray1, size1);
    printf("Total # of swaps: %d\n", bubbleSort(resetArray1, size1));


    printf("\nARRAY 2: \n");
    printf("SELECTION SORT:\n");
    swapCount(array2, size2);
    printf("Total # of swaps: %d\n", selectionSort(array2, size2));

    int resetArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    printf("BUBBLE SORT:\n");
    swapCount(resetArray2, size2);
    printf("Total # of swaps: %d\n", bubbleSort(resetArray2, size2));

    return 0;
}