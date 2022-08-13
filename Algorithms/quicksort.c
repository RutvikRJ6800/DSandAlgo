/* QUICKSORT ALGORITHM */
/* MERGE SORT */
#include<stdio.h>

/* Functions Prototype  */

void printArray(int *,int);
int partition(int *,int,int);
void quickSort(int *,int,int);
void exchange(int*,int*);

/* EXCHANGE FINCTION */

void exchange(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; 
}

/* PARTITION PROCEDURE */

int partition(int *pt,int p,int r){
    int key,i,j;
    key = pt[r];
    i = p-1;
    for(j = p ; j < r; j++){
        if(pt[j] <= key){
            i = i+1;
            exchange(pt + i,pt + j);
        }        
    }
    exchange(pt + i+1,pt + r);
    return i+1;
    
}

/* QUICKSORT */

void quickSort(int *pt,int p,int r){
    if(p<r){
        int q = partition(pt,p,r);
        quickSort(pt,p,q-1);
        quickSort(pt,q+1,r);
    }
}

/* Function to PRINT An ARRAY */

void printArray(int *pt,int n){
    int i;
    for(i = 0; i<n ;i++){
        printf("%d ",pt[i]);
    }
}

/* MAIN FUNCTION */

int main(void){
    int arr[8] = {10,9,8,7,6,5,4,3};
    quickSort(arr,0,7);
    printArray(arr,8);
    getch();
    return 0;
}