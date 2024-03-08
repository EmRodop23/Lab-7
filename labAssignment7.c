#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapCount(int freqarr[][2], int n){
    for (int i=0; i<9; i++){
        if(freqarr[i][0] == n){
            freqarr[i][1]++;
            return;
        }
    }
}

void reset(int arr[], int resetArr[], int freqArr[][2]){
    for(int i=0; i<9; i++){
        arr[i] = resetArr[i];
        freqArr[i][1] = 0;
    }
}

int bubbleSort(int arr[], int n, int freqarr[][2]){
    int temp;
    int count = 0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&(arr[j]), &(arr[j+1]));
                swapCount(freqarr, arr[j]);
                swapCount(freqarr, arr[j+1]);
                count++;
            }
        }
    }
    return count;
}

int selectionSort(int arr[], int n, int freqarr[][2]){
    int minIndex = 0;
    int temp;
    int count = 0;

    for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            swapCount(freqarr, arr[i]);
            swapCount(freqarr, arr[minIndex]);
            count++;
        }
    }
    return count;
}

int main(){
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int resetArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int freqArr1[9][2] = {{7, 0},{13, 0},{16, 0},{22, 0},{45,0},{58,0},{63,0},{72,0},{97,0}};
    int size1 = 9;
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int resetArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int freqArr2[9][2] = {{10, 0},{20, 0},{30, 0},{40, 0},{50,0},{60,0},{70,0},{80,0},{90,0}};
    int size2 = 9;

    printf("ARRAY 1: \n");
    printf("SELECTION SORT:\n");
    printf("Total # of swaps: %d\n", selectionSort(array1, size1, freqArr1));
    for(int i=0; i<size1; i++){
        printf("%d: swapped %d time(s)\n", freqArr1[i][0], freqArr1[i][1]);
    }

    reset(array1, resetArray1, freqArr1);

    printf("\nBUBBLE SORT:\n");
    printf("Total # of swaps: %d\n", bubbleSort(array1, size1, freqArr1));
    for(int i=0; i<size1; i++){
        printf("%d: swapped %d time(s)\n", freqArr1[i][0], freqArr1[i][1]);
    }


    printf("\nARRAY 2: \n");
    printf("SELECTION SORT:\n");
    printf("Total # of swaps: %d\n", selectionSort(array2, size2, freqArr2));
    for(int i=0; i<size1; i++){
        printf("%d: swapped %d time(s)\n", freqArr2[i][0], freqArr2[i][1]);
    }

    reset(array2, resetArray2, freqArr2);

    printf("\nBUBBLE SORT:\n");
    printf("Total # of swaps: %d\n", bubbleSort(array2, size2, freqArr2));
    for(int i=0; i<size1; i++){
        printf("%d: swapped %d time(s)\n", freqArr2[i][0], freqArr2[i][1]);
    }

    return 0;
}