// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int target) {
	    // code here
	    int a=-1;
    int b=-1;
    
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]<target){
            s=mid+1;
        }else{
            a=mid;
            e=mid-1;
        }
    }

    if(a >= 0 && a<n && arr[a] != target) a = -1;
    
    s=0;
    e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid] > target){
            e=mid-1;
        }else{
            s=mid+1;
            b=mid;
        }
    }

    if(b >= 0 && b<n && arr[b] != target) b = -1;
        
    if(a == -1 || b == -1) return 0;
    return (b - a + 1);
    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends