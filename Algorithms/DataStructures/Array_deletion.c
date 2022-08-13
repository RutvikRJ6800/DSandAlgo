// Program for deleting existing value at index k into existing Arrray of size 
#include<stdio.h>
void main(){
    // Static declaration for LA(Linear Array) and index from where delete the value
    int LA[] = {1,2,3,4,5};
    int i,j,index,n,val;
    n = 5;
    index = 2;
    val = 10;
    printf("Original Array\n");
    for (i=0; i<n; i++){
        printf("LA[%d] : %d\n",i,LA[i]);
    }
    // Removing space of deleted element by shifting others
    j = index;
    while(j<n){
        LA[j] = LA[j+1];
        j++;
    }
    n--;
    // Printing New  Array
    printf("New Array\n");
    for(i = 0;i<n;i++){
        printf("LA[%d] : %d\n",i,LA[i]);
    }
}