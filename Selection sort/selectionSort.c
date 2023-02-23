#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *y, int *x){
    int temp;
    temp = *x;      
    *x = *y;    
    *y = temp;  
}

void selectionSort(int inputArr[], int length){
    for (int i = 0; i < length; i++)
    {
        int minValueIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (inputArr[j] < inputArr[minValueIndex])
            {
                minValueIndex = j;
            }
        }
        if (minValueIndex != i)
        {
            swap(&inputArr[i], &inputArr[minValueIndex]);
        }
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
    //int inputArr[] = {67, 32, 95, 11, 89, 24, 73, 52, 7, 61};
    //int length = sizeof(inputArr) / sizeof(int);
    
    int numCount = 500000;
    int *inputArr = genRanNums(numCount);
    
    clock_t start, end;
    double cpu_time_used;
    //printf("Input\n");
    //printArr(inputArr, numCount);
    //printf("\n");

    start = clock();
    selectionSort(inputArr, numCount);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time to run: %f sec", cpu_time_used);
    //printf("Output\n");
    //printArr(inputArr, numCount);

    return 0;
}
