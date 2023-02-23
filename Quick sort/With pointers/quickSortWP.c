#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArr(int inputArr[], int  length){
    for (int i = 0; i < length; i++)
    {    
        printf("%d ", inputArr[i]);
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
    int numCount = 10;
    int *inputArr = genRanNums(numCount);

    clock_t start, end;
    double cpu_time_used;

    printf("Input:\n");
    printArr(inputArr, numCount);
    printf("\n");
    start = clock();
    quicksort(inputArr, 0, numCount - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time to run: %f sec", cpu_time_used);
    printf("Output:\n");
    printArr(inputArr, numCount);
    printf("\n");

    return 0;
}