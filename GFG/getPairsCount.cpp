// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int getPairsCount(int arr[], int n, int k) {
        // code here
        // approch 1: brut force O(n2) time
        // int count=0;
        // for(int i=0; i<n;i++){
        //     int curr = arr[i];
        //     int weWant = k-curr;
        //     for(int j=i+1; j<n; j++){
        //         if(arr[j]==weWant){
        //             count++;    
        //         }
        //     }
        // }
        // return count;
        
        // int s = sizeof(arr) / sizeof(arr[0]);
            
        // approch 2: using unordered map : O(n) time and O(n) memory
        unordered_map<int,int> m;
        int count=0;
        for(int i=0;i<n; i++){
            
            int need=k-arr[i];
            if(m[need]){
                count +=m[need];
            }
            m[arr[i]]++;
            
        }
        return count;    
            
            
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends