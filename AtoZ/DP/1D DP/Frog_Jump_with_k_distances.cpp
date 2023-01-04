// https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*
    
    // RECURSIVE APPROACH
    
    int solve(vector<int> &height, int idx, int &k){
        if(idx == 0) return 0;
        else if(idx < 0) return 1e8;
        
        int ans = INT_MAX;
        for(int i=1; i<=k; i++){
            int cost = abs(height[idx] - height[idx-i]) + solve(height, idx-i, k); 
            ans = min(ans, cost);
        }
        
        return ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return solve(height, n-1, k);
    }*/
    
    
    
    // MEMOIZATION APPROACH
    /*int solve(vector<int> &height, int idx, int &k, vector<int> &dp){
        if(idx == 0) return 0;
        else if(idx < 0) return 1e8;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = INT_MAX;
        for(int i=1; i<=k; i++){
            int cost = abs(height[idx] - height[idx-i]) + solve(height, idx-i, k, dp); 
            ans = min(ans, cost);
        }
        
        return dp[idx] = ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n, -1);
        return solve(height, n-1, k, dp);
    }*/
    
    
    
    // TABULATION APPROACH
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n, 0);
        
        
        for(int i=1; i<n; i++){
            int ans = INT_MAX;
            for(int j=1; j<=k; j++){
                int idx = i-j;
                if(idx < 0 ) break;
                ans = min(ans, dp[idx] + abs(height[idx] - height[i]));
            }
            dp[i] = ans;
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends