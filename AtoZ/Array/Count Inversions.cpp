// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long start, long long mid, long long end){
        // cout<<start<<","<<end<<endl;
        long long int i=start, j=mid, k=0LL;
        vector<long long> temp(end-start+1);
        long long int ans = 0;
        while(i<mid && j<=end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                ans += (mid-i);
                temp[k++] = arr[j++];
            }
        }
        while(i<mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }
        i=start, k=0;
        while(i<=end){
            arr[i++] = temp[k++];
        }
        return ans;
    }
    long long int mergeSort(long long arr[], long long start, long long end){
        long long int ans = 0;
        // cout<<start<<","<<end<<endl;
        if(start<end){
            long long mid = start + (end-start)/2;
            ans += mergeSort(arr, start, mid);
            ans += mergeSort(arr, mid+1, end);
            ans += merge(arr, start, mid+1, end);
            return ans;
        }
        else return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends