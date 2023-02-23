#include <stdio.h> 
#include <stdlib.h>

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