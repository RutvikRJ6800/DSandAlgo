/*
// Recursive approachs
long long int rec(vector<int>& coins, int amount, int idx, int cnt){
        // if(N==0 || sum==0) return 0;
        if(amount==0) return cnt;
        if(idx == 0) return INT_MAX;
        
        if(coins[idx-1] <= amount){
            return min(rec(coins, amount -coins[idx-1], idx, cnt+1) , rec(coins, amount, idx-1, cnt));
        }
        else{
            return rec(coins, amount, idx-1, cnt);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        int res  = rec(coins, amount, n, 0);
        if(res == INT_MAX) return -1;
        else return res;

    }
*/

/* *********************************
    BOTTOM - UP APPROACH
  **********************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        sort(coins.begin(), coins.end());

        for(int i=0; i<amount+1; i++){
            dp[0][i] = INT_MAX-1;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+ dp[i][j-coins[i-1]], dp[i-1][j]); 
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int res = dp[n][amount];
        if(res == INT_MAX-1) return -1;
        else return res;

    }
};