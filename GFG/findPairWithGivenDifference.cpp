// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#
// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    // }
    
  
    return 0;
}// } Driver Code Ends

bool binSearch(int arr[],int l,int r,int key){
    while (l<=r)
    {
        int m = (l+r)/2;
        if(arr[m]==key){
            return true;
        }
        else if(arr[m]<key){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return false;
    
}
bool findPair(int arr[], int size, int n){
    //code
    
    // use sorting O(nlogn) time constant space;
    sort(arr,arr+size);
    for(int i=size-1; i>=1; i--){
        int key = arr[i]-n;
        if(key<0) continue;
        if(binSearch(arr,0,i-1,key)){
            return true;
        }
    }
    return false;

    
    
    

    
}