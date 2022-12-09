//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /*
    RECURSIVE APPROACH 
    long long int rec(int coins[], int N, int sum){
        // if(N==0 || sum==0) return 0;
        if(sum==0) return 1;
        if(N==0) return 0;
        
        if(coins[N-1] <= sum){
            return (rec(coins, N, sum-coins[N-1]) + rec(coins, N-1, sum));
        }
        else{
            return rec(coins, N-1, sum);
        }
    }
    long long int count(int coins[], int N, int sum) {
    
        // code here.
        return rec(coins, N, sum);
    } */
    
    
    /*
    Memoization Approach 
    long long int rec(int coins[], int N, int sum, vector<vector<long long int>> &dp){
        // if(N==0 || sum==0) return 0;
        if(sum==0) return 1;
        if(N==0) return 0;
        
        if(dp[N][sum]!= -1) return dp[N][sum];
        if(coins[N-1] <= sum){
            dp[N][sum] = (rec(coins, N, sum-coins[N-1], dp) + rec(coins, N-1, sum, dp));
            return dp[N][sum];
        }
        else{
            dp[N][sum] = rec(coins, N-1, sum, dp);
            return dp[N][sum];
        }
    }
    long long int count(int coins[], int N, int sum) {
    
        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int> (sum+1,-1));
        return rec(coins, N, sum, dp);
    }
    */

   // Top - Down Approach   
   long long int count(int coins[], int N, int sum) {
    
        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int> (sum+1,-1));
        for(int i=0; i<N+1; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<sum+1; i++){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<N+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends   