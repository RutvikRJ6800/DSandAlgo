// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:

    /*
    RECURSION AND DP APPROACH 
    int solve(vector<int>& prices, int idx, bool canBuy, int n, vector<vector<int>> &dp){
        if(idx == n) return 0;
        
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        if(canBuy){
            return dp[idx][canBuy] = max(-prices[idx]+solve(prices, idx+1, 0, n, dp), solve(prices, idx+1, 1, n, dp));
        }
        else{
            // we can sell
            return dp[idx][canBuy] = max(prices[idx] + solve(prices, idx+1, 1, n, dp), solve(prices, idx+1, 0, n, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return solve(prices, 0, 1, size, dp);
    }
 */

    // TABULIZATION APPRAOCH
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size+1, vector<int>(2, 0));
        
        for(int i=size-1; i>=0; i--){
            dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);// can not buy stock (sell it or keep it).
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);// can buy stock .
        }

        return dp[0][1];
    }
};