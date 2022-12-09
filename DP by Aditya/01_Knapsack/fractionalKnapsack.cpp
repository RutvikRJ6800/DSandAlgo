//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    /* 
    RECURSIVE APPROACH :: gives TLE
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W==0 || n == 0) return 0;
       else{
           if(wt[n-1] <= W){
               // take or not take
               return max(val[n-1] + knapSack(W-wt[n-1  ], wt, val, n-1), knapSack(W, wt, val, n-1));
           }
           else{
               return knapSack(W, wt, val, n-1);
           }
       }
    } */

    /*
    // MEMOIZATION APPROACH:: 
    int rec(int W, int wt[], int val[], int n, vector<vector<int>> &dp){
       if(W==0 || n == 0) return 0;
       else{
           if(dp[n][W]!=-1) return dp[n][W];
           if(wt[n-1] <= W){
               // take or not take
               dp[n][W] = max(val[n-1] + rec(W-wt[n-1], wt, val, n-1, dp), rec(W, wt, val, n-1, dp));
               return dp[n][W];
           }
           else{
               dp[n][W] = rec(W, wt, val, n-1, dp);
               return dp[n][W];
           }
       } 
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       return rec(W, wt, val, n, dp);
    } */

    // BOTTOM - UP APPROACH
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
       for(int i=1; i<n+1; i++){
           for(int j=1; j< W+1; j++){
               if(wt[i-1] <= j){
                   // 2 option take and not take
                   dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }

};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends