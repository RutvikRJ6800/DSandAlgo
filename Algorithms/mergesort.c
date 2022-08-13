/* MERGE SORT */
#include<stdio.h>

/* Functions Prototype  */

void printArray(int *,int);
void merge(int *,int,int,int);
void mergesort(int *,int,int);

/* MERGE PROCEDURE */

void merge(int *pt,int p,int q,int r){
    int n,m,i,j,k;
    n = q - p + 1;
    m = r - q;
    int arr1[n+1],arr2[m+1];
    arr1[n] = 9999; arr2[m] = 9999;
    for(i = 0; i<n; i++){
        arr1[i] = pt[p+i];
    }
    for(j = 0; j < m; j++){
        arr2[j] = pt[q+j+1];
    }


    i = 0,j = 0;
    for (k = p; k <= r; k++)
    {
        if(arr1[i]<arr2[j]){
            pt[k] = arr1[i];
            i++;
        }
        else
        {
            pt[k] = arr2[j];
            j++;
        }
        
    }
    
}

/* MERGESORT */

void mergesort(int *pt,int p,int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(pt,p,q);
        mergesort(pt,q+1,r);
        merge(pt,p,q,r);
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
    mergesort(arr,0,7);
    printArray(arr,8);
    getch();
    return 0;
}