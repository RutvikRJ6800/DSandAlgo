// Program for adding new value at index k into existing Arrray of size 
#include<stdio.h>
void main(){
    // Static declaration for LA(Linear Array) and new value
    int LA[] = {1,2,3,4,5};
    int i,j,k,n,val;
    n = 5;
    k = 2;
    val = 10;
    printf("Original Array\n");
    for (i=0; i<n; i++){
        printf("LA[%d] : %d\n",i,LA[i]);
    }
    // Making space for New element by shifting
    j = n;
    while(j>=k){
        LA[j+1] = LA[j];
        j--;
    }
    LA[k] = val;
    n++;
    // Printing New  Array
    printf("New Array\n");
    for(i = 0;i<n;i++){
        printf("LA[%d] : %d\n",i,LA[i]);
    }
}