/* INSERTION SORT */
#include<stdio.h>
void printArray(int *,int);
void sort(int *p,int n){
    int i,j,key;
    for( j = 1 ; j < n; j++){
        key = p[j];
        i = j-1;
        while(i >= 0 && p[i] > key){
            p[i + 1] = p[i];
            i--;
        }
        p[i+1] = key;
    }
    printArray(p,n);

}
void printArray(int *p,int n){
    int i;
    for(i = 0; i<n ;i++){
        printf("%d ",p[i]);
    }
}
int main(void){
    int arr[5] = {10,9,8,7,6};
    sort(arr,5);

}
