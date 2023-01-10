class Solution {
public:
    int solve(vector<int>& prices, int idx, int n, bool canBuy, vector<vector<int>> &dp){
        if(idx >= n) return 0;

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        if(canBuy){
            return dp[idx][canBuy] = max(-prices[idx] + solve(prices, idx+1, n, 0, dp), solve(prices, idx+1, n, 1, dp));
        }
        else{
            // we can sell or not sell
            return dp[idx][canBuy] = max(prices[idx] + solve(prices, idx+2, n, 1, dp), solve(prices, idx+1, n, 0, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        

        for(int idx=n-1; idx>=0; idx--){
            dp[idx][1] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            dp[idx][0] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
        }

        return dp[0][1];
    }
};