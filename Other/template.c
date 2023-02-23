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

int main()
{
    printf("Hello, world!\n"); 
    int inputArr[] = {67, 32, 95, 11, 89, 24, 73, 52, 7, 61};
    int length = sizeof(inputArr) / sizeof(int);

    int tun = 17;
    int *pTun = &tun;

    printf("*ptun p = %p \n", *pTun); 
    printf("ptun p = %p \n", pTun); 
    printf("*ptun d = %d \n", *pTun); 
    printf("ptun d = %d \n", pTun); 

    return 0;
}
