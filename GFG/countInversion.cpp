// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=814s
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long temp[],long long left,long long mid,long long right)
{
    long long inv_count=0;
    long long i=left;
    long long j=mid;
    long long k=left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}


long long int _mergesort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += _mergesort(arr,temp,left,mid);
        inv_count += _mergesort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        for(int i=0; i<N; i++){
            temp[i]=0;
        }
        return _mergesort(arr,temp, 0,N-1);
    }

};

// { Driver Code Starts.

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