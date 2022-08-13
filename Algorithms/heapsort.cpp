#include<conio.h>
#include<iostream>
using namespace std;
void printArray(int* p,int n){
	for (int i = 0; i<n; i++){
		cout<<p[i]<<ends;
	}
	cout<<endl;
}
void swap(int * a, int *b){
	int temp;
	temp = *a;
	*b = *a;
	*a = temp;
}
void heapify(int arr[],int n,int i){
	int largest,l,r;
	l = 2*i + 1;
	r = 2*i + 2;
	if(l < n  && arr[l]>arr[i]){
		largest = l;
	}
	else
	largest = i;
	if(r < n && arr[r]>arr[i]){
		largest = r;
	}
	else
	largest = i;
	if(largest != i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
	
}
void built_heap(int arr[],int n){
	for (int i = n/2; i>=0; i--){
		heapify(arr,n,i);
		
	}
	printArray(arr,n);
}
void heap_sort(int arr[],int n){
	built_heap(arr,n);
	for(int i = n; i>0; i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

int main(){
	int arr[] = {12,11,13,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	heap_sort(arr,n);
	printArray(arr,n);
	
}
