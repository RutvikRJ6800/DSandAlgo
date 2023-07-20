// https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401?leftPanelTab=0

#include <bits/stdc++.h>

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
    sort(arr, arr + n);
    
	pair<int, int>ans;
    int a=-1;
    int b=-1;
    
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]<=x){
            a=arr[mid];
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    
    s=0;
    e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=x){
            b=arr[mid];
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    ans.first=a;
    ans.second=b;
    return ans;
}
