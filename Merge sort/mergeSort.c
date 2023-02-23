#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
//#include "utilities.h"

void printArr(int inputArr[], int  length){
    for (int i = 0; i < length; i++){    
        printf("%d ", inputArr[i]);
    }
}

void merge(int arr[], int startIndex, int middleIndex, int endIndex, int arrLength){
    int temp[arrLength];
    int i, midI, k;
    i = startIndex;
    midI = middleIndex + 1;
    k = startIndex;

    while (i <= middleIndex && midI <= endIndex){
        if (arr[i] <= arr[midI]){ 
            temp[k++] = arr[i++];
        } else{
            temp[k++] = arr[midI++]; 
        }
    }
    while (i <= middleIndex){
        temp[k++] = arr[i++];
    }
    while (midI <= endIndex){ 
        temp[k++] = arr[midI++]; 
    }

    for (i = startIndex; i <= endIndex; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int startIndex, int endIndex, int arrLength){
    if(startIndex < endIndex){
        int middleIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, middleIndex, arrLength);
        mergeSort(arr, (middleIndex + 1), endIndex, arrLength);

        merge(arr, startIndex, middleIndex, endIndex, arrLength);
    }
}

int* genRanNums(int numCount){
    int min = 1;
    int max = 1000000;
    int* ranNum = malloc(numCount *sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        ranNum[i] = min + rand() % (max - min + 1);
    }

    return ranNum;
}

int main()
{
    //int inputArr[] = {67, 32, 95, 11, 89, 24, 73, 52, 7, 61};
    //int length = sizeof(inputArr) / sizeof(int);

    int numCount = 1000000;
    int *inputArr = genRanNums(numCount);

    clock_t start, end;
    double cpu_time_used;
    //printf("Input:\n");
    //printArr(inputArr, numCount);
    //printf("\n");

    start = clock();
    mergeSort(inputArr, 0, numCount - 1, numCount);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time to run: %f sec", cpu_time_used);
    //printf("Output:\n");
    //printArr(inputArr, numCount);

    return 0;
}
