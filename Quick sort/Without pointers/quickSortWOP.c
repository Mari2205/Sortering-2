#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int left, int right) {
   int i = left, j = right;
   int tmp;
   int pivot = arr[(left + right) / 2];

   while (i <= j) {
      while (arr[i] < pivot)
         i++;
      while (arr[j] > pivot)
         j--;
      if (i <= j) {
         tmp = arr[i];
         arr[i] = arr[j];
         arr[j] = tmp;
         i++;
         j--;
      }
   }

   if (left < j)
      quickSort(arr, left, j);
   if (i < right)
      quickSort(arr, i, right);
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
    int numCount = 1000000000;
    int *inputArr = genRanNums(numCount);

    clock_t start, end;
    double cpu_time_used;
    //printf("Input:\n");
    //printArr(inputArr, numCount);
    //printf("\n");
    start = clock();
    quickSort(inputArr, 0, (numCount - 1));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time to run: %f sec", cpu_time_used);
    //printf("Output:\n");
    //printArr(inputArr, numCount);
    //printf("\n");

    return 0;
}