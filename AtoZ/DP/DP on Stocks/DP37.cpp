class Solution {
public:
/*
    int solve(vector<int> &prices, int idx, int size, int attempt, bool canBuy, vector<vector<vector<int>>> &dp){
        // base case
        if(idx == size) return 0;

        if(dp[idx][attempt][canBuy] != -1) return dp[idx][attempt][canBuy];
        if(!canBuy){
            // can't buy
            return dp[idx][attempt][canBuy] = max(prices[idx] + solve(prices, idx+1, size, attempt, 1, dp), solve(prices, idx+1, size, attempt, 0, dp));
        }
        else{
            if(attempt>0){
            return dp[idx][attempt][canBuy] = max(-prices[idx] + solve(prices, idx+1, size, attempt-1, 0, dp), solve(prices, idx+1, size, attempt,  1, dp));
            }
            else{
                return  dp[idx][attempt][canBuy] = 0;
            }
        }
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        vector<vector<vector<int>>> dp(size, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(prices, 0, size, 2, 1, dp);
        
    }*/

    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(3, vector<int>(2, 0)));
        
        for(int idx=size-1; idx>=0; idx--){
            // can't buy
            dp[idx][0][0] = max(prices[idx] + dp[idx+1][0][1], dp[idx+1][0][0]);
            dp[idx][1][0] = max(prices[idx] + dp[idx+1][1][1], dp[idx+1][1][0]);
            dp[idx][2][0] = max(prices[idx] + dp[idx+1][2][1], dp[idx+1][2][0]);
            
            dp[idx][1][1] = max(-prices[idx] + dp[idx+1][0][0], dp[idx+1][1][1]);
            dp[idx][2][1] = max(-prices[idx] + dp[idx+1][1][0], dp[idx+1][2][1]);
            dp[idx][0][1] = 0;
            
        }

        // return max({dp[0][1][1], dp[0][2][1], dp[0][0][1]});
        return dp[0][2][1];
        
    }
};