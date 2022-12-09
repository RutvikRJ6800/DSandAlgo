//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /* Recursive solution - gives time limit
     bool rec(vector<int> &arr, int sum, int n){
        // base condition
        if(sum == 0) return true;
        if(n == 0 && sum != 0) return false;
        else{
            // select apropriate choice
            if(arr[n-1] <= sum){
                // 2 choice take and not take
                return (rec(arr, sum-arr[n-1], n-1) || rec(arr, sum, n-1));
            }
            else{
                // 1 choice not take
                return rec(arr, sum, n-1);
            }
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        return rec(arr, sum, n);
    } */
    /*
    // MEMOISATION APPROACH

    bool rec(vector<int> &arr, int sum, int n, vector<vector<int>> &dp){
        // base condition
        if(sum == 0) return true;
        if(n == 0 && sum != 0) return false;
        else{
            // see if result already computed
            if(dp[n][sum] != -1) return dp[n][sum];
            // select apropriate choice
            if(arr[n-1] <= sum){
                // 2 choice take and not take
                dp[n][sum] = (rec(arr, sum-arr[n-1], n-1, dp) || rec(arr, sum, n-1, dp));
                return dp[n][sum];
            }
            else{
                // 1 choice not take
                dp[n][sum] = rec(arr, sum, n-1, dp);
                return dp[n][sum];
            }
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return rec(arr, sum, n, dp);
    }
    */
   bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0; i<n+1; i++){
            // put 1 for sum = 0 column
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j){
                    // two choice
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
                else{
                    // only one choice
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }



};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends