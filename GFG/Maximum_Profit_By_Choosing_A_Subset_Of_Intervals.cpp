//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    static bool cmptr(vector<int> &a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        else{
            return a[1] < b[1];
        }
    }
    int solve(vector<vector<int>> &intervals, int idx, int end, int n, vector<int> &dp){
        if(idx == n) return 0;
        
        if(dp[end] != -1) return dp[end];
        if(end <= intervals[idx][0]){
            // take not take
            return dp[end] = max(intervals[idx][2] + solve(intervals, idx+1, max(end, intervals[idx][1]), n, dp) , 0 + solve(intervals, idx+1, end, n, dp));
        }
        
        return dp[end] = solve(intervals, idx+1, end, n, dp);
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), cmptr);
        vector<int> dp(1e5+1, -1);
        return solve(intervals, 0, 0, n, dp);
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends