#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *y, int *x){
    int temp;
    temp = *x;      
    *x = *y;    
    *y = temp;  
}

void printArr(int inputArr[], int  length){
    for (int i = 0; i < length; i++)
    {    
        printf("%d ", inputArr[i]);
    }
}

void insertionSort(int inputArr[], int  length){
    for (int i = 1; i < length; i++)
    {
        int nextItem = inputArr[i];
        int j = i - 1;

        while (j >= 0 && inputArr[j] > nextItem)
        {
            inputArr[j + 1] = inputArr[j];
            j--;
        }
        j++;
        inputArr[j] = nextItem;
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

    int numCount = 500000;
    int *inputArr = genRanNums(numCount);
    
    clock_t start, end;
    double cpu_time_used;
    //printf("input:\n");
    //printArr(inputArr, numCount);
    //printf("\n");

    start = clock();
    insertionSort(inputArr, numCount);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time to run: %f sec", cpu_time_used);
    //printf("Output:\n");
    //printArr(inputArr, numCount);

    return 0;
}
