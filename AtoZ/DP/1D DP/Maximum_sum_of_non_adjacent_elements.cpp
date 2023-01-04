// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // MEMOIZATION APPROACH
    
    /*int solve(int *arr, int idx, int *dp){
        if(idx<0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        // take not take
        return dp[idx] = max(arr[idx] + solve(arr, idx-2, dp), solve(arr, idx-1, dp));
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int dp[n];
	    memset(dp, -1, sizeof(dp));
	    return solve(arr, n-1, dp);
	}*/
	
	// TABULATION APPROACH
	/*int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    int dp[n];
	    dp[0] = arr[0];
	    dp[1] = max(arr[1], arr[0]);
	    
	    for(int i=2; i<n; i++){
        
            // take not take
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
	    }
	    return dp[n-1];
	}*/
	
	//TABULATION WITH SPACE OPTIMIZATION
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    
	    int prev2 = arr[0];
	    int prev = max(arr[1], arr[0]);
	    int ans = INT_MIN;
	    for(int i=2; i<n; i++){
        
            // take not take
            ans = max(arr[i] + prev2, prev);
            prev2 = prev;
            prev = ans;
	    }
	    return prev;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends